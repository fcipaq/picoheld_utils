#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int putc_super(FILE* f, uint8_t* buf, int len) {
  for (int h = 0; h < len; h++) {
    fprintf(f, "0x%02x", buf[h]);
    if (h != len - 1)
      fprintf(f, ", ");
    if ((h + 1) % 16 == 0)
      fprintf(f, "\n");
  }
  return len;
}

int main(int argc, char** argv) {
  printf("Welcome to font converter.\n\n");
  printf("This converter decompresses .font files and converts them to.\n");
  printf("be used with the Pico Pad library.\n\n");

  if (argc < 3 || argc > 4) {
    printf("Usage font_conv [input file] [output file] [ascii art: y].\n");
    return -1;
  }

  if (sizeof(uint32_t) != 4 || sizeof(uint16_t) != 2) {
    printf("Type size incorrect. Please recompile.\n");
    return -1;
  }

  uint8_t show_glyphs = 0;  // shows glyphs in terminal windows as "ascii art"
  if (argc == 4)
    if (argv[3][0] == 'y' && argv[3][1] == 0) {
      show_glyphs = 1;  // shows glyphs in terminal windows as "ascii art"
    } else {
      printf("3rd argument must be y or omitted.\n");
      return -1;
    }

  FILE* f_in = fopen(argv[1], "rb");
  FILE* f_out = fopen(argv[2], "w");

  uint32_t bytes_read = 0;

  uint16_t font_size = 0;
  uint8_t font_width = 0;
  uint8_t font_height = 0;
  uint8_t font_bpp = 0;

  uint8_t font_First_Char = 0;
  uint8_t font_Last_Char = 0;

  uint8_t font_padding = 0;
  uint8_t font_RLE_table[4];

  uint8_t hib, lob = 0;
  bytes_read += fread(&hib, 1, 1, f_in);

  bytes_read += fread(&lob, 1, 1, f_in);
  ;
  font_size = 256 * hib + lob;

  bytes_read += fread(&font_width, 1, 1, f_in);
  bytes_read += fread(&font_height, 1, 1, f_in);
  bytes_read += fread(&font_bpp, 1, 1, f_in);

  if (font_bpp & 0x80 == 0) {
    printf("Not a compressed font file or incompatible.\n");
    fclose(f_in);
    fclose(f_out);
    return -1;
  }

  if ((font_bpp & 0x7F) != 1) {
    printf("Currently only 1 bpp fonts are supported (or I/O error).\n");
    fclose(f_in);
    fclose(f_out);
    return -1;
  }


  printf("font size is:    %d bytes\n", font_size);
  printf("font width is:   %d pixels\n", font_width);
  printf("font height is:  %d pixels\n", font_height);

  bytes_read += fread(&font_First_Char, 1, 1, f_in);
  bytes_read += fread(&font_Last_Char, 1, 1, f_in);

  uint8_t font_Char_Width[font_Last_Char - font_First_Char + 1];
  bytes_read += fread(font_Char_Width, 1, font_Last_Char - font_First_Char + 1, f_in);

  printf("font 1st char:   %d\n", font_First_Char);
  printf("font lst char:   %d\n", font_Last_Char);

  // compressed
  bytes_read += fread(&font_padding, 1, 1, f_in);
  bytes_read += fread(&font_RLE_table[1], 1, 3, f_in);
  font_RLE_table[0] = 1;
  uint8_t font_Char_Size_in_Bytes[font_Last_Char - font_First_Char + 1];

  printf("byte padding:    %d\n", font_padding);

  bytes_read += fread(font_Char_Size_in_Bytes, 1, font_Last_Char - font_First_Char + 1, f_in);

  printf("header size is:  %d bytes\n", bytes_read);

  // data
  uint8_t font_data[font_size - bytes_read + 1];

  fread(font_data, 1, font_size - bytes_read + 1, f_in);

  uint8_t font_data_out[font_width * font_height * (font_Last_Char - font_First_Char + 1)];
  uint32_t num_bytesout = 0;

  uint8_t bitencode = 0;
  uint8_t font_byte = 0;

  for (uint16_t c = font_First_Char; c < font_Last_Char + 1; c++) {
    uint16_t bits = 0;
    uint8_t bitscount = 0;

    uint16_t data = 0;
    uint32_t index = 0;

    if (show_glyphs) {
      printf("char num:   %d\n", c - 1);
      printf("char width: %d pixels\n", font_Char_Width[c - font_First_Char]);
    }

    for (int i = font_First_Char; i < c; i++) {
      index += font_Char_Size_in_Bytes[data++];
    }

    index *= font_padding;
    data = index;
    bits = font_data[data++];
    bitscount = 8;

    font_size <<= 8;

    //*********************
    uint8_t pixelcount = 0;
    uint16_t pixelcolor = 0;
    uint8_t bitspixel = font_bpp & 0x7F;
    uint8_t bitsmask = 0xFF >> (8 - bitspixel);

    uint8_t fb[font_width][font_height];

    for (int x = 0; x <= font_Char_Width[c - font_First_Char] - 1; x++) {
      for (int y = 0; y <= font_height - 1; y++) {
        if (pixelcount == 0) {
          if (bitscount <= 8) {
            bits |= font_data[data++] << bitscount;
            bitscount += 8;
          }
          pixelcount = font_RLE_table[bits & 3];
          bits >>= 2;
          bitscount -= 2;
          pixelcolor = bits & bitsmask;
          bits >>= bitspixel;
          bitscount -= bitspixel;
        }
        pixelcount--;
        bitencode++;

        font_byte >>= 1;
        font_byte |= pixelcolor * 128;

        if (bitencode == 8) {
          font_data_out[num_bytesout++] = font_byte;
          font_byte = 0;
          bitencode = 0;
        }

        fb[x][y] = pixelcolor;
      }
    }

    if (show_glyphs) {
      for (int y = 0; y <= font_height - 1; y++) {
        for (int x = 0; x <= font_Char_Width[c - font_First_Char] - 1; x++) {
          if (fb[x][y])
//            printf("%c", #);
            printf("#");
          else
            printf("_");
        }
        printf("\n");
      }
    }
  }

  printf("Decompression complete.\n");

  font_size = 7 + font_Last_Char - font_First_Char + 1 + num_bytesout;

  printf("Saving font file.\n");

  fprintf(f_out, "/*\n");
  fprintf(f_out, "    created with FontEditor written by H. Reddmann\n");
  fprintf(f_out, "    HaReddmann at t-online dot de\n");
  fprintf(f_out, "\n");
  fprintf(f_out, "    File Name           : %s.h\n", argv[2]);
  //fprintf(f_out, "    Date                : 11.05.2023\n");
  fprintf(f_out, "    Font size in bytes  : 0x%04x, %d\n", font_size, font_size);
  fprintf(f_out, "    Font width          : %d\n", font_width);
  fprintf(f_out, "    Font height         : %d\n", font_height);
  fprintf(f_out, "    Font first char     : 0x%02x\n", font_First_Char);
  fprintf(f_out, "    Font last char      : 0x%02x\n", font_Last_Char);
  fprintf(f_out, "    Font bits per pixel : %d\n", font_bpp & 0x7F);
  fprintf(f_out, "    Font is compressed  : false\n");
  fprintf(f_out, "\n");
  fprintf(f_out, "    The font data are defined as\n");
  fprintf(f_out, "\n");
  fprintf(f_out, "    struct _FONT_ {\n");
  fprintf(f_out, "     // common shared fields\n");
  fprintf(f_out, "       uint16_t   font_Size_in_Bytes_over_all_included_Size_it_self;\n");
  fprintf(f_out, "       uint8_t    font_Width_in_Pixel_for_fixed_drawing;\n");
  fprintf(f_out, "       uint8_t    font_Height_in_Pixel_for_all_Characters;\n");
  fprintf(f_out, "       uint8_t    font_Bits_per_Pixels;\n");
  fprintf(f_out, "                    // if MSB are set then font is a compressed font\n");
  fprintf(f_out, "       uint8_t    font_First_Char;\n");
  fprintf(f_out, "       uint8_t    font_Last_Char;\n");
  fprintf(f_out, "       uint8_t    font_Char_Widths[font_Last_Char - font_First_Char +1];\n");
  fprintf(f_out, "                    // for each character the separate width in pixels,\n");
  fprintf(f_out, "                    // characters < 128 have an implicit virtual right empty row\n");
  fprintf(f_out, "                    // characters with font_Char_Widths[] == 0 are undefined\n");
  fprintf(f_out, "\n");
  fprintf(f_out, "     // if compressed font then additional fields\n");
  fprintf(f_out, "       uint8_t    font_Byte_Padding;\n");
  fprintf(f_out, "                    // each Char in the table are aligned in size to this value\n");
  fprintf(f_out, "       uint8_t    font_RLE_Table[3];\n");
  fprintf(f_out, "                    // Run Length Encoding Table for Decompression\n");
  fprintf(f_out, "       uint8_t    font_Char_Size_in_Bytes[font_Last_Char - font_First_Char +1];\n");
  fprintf(f_out, "                    // for each char the size in (bytes / font_Byte_Padding) are stored,\n");
  fprintf(f_out, "                    // this get us the table to seek to the right beginning of each char\n");
  fprintf(f_out, "                    // in the font_data[]. Withhelp of font_Byte_Padding we ensure that\n");
  fprintf(f_out, "                    // one byte is suitable to store character sizes greater 255\n");
  fprintf(f_out, "\n");
  fprintf(f_out, "     // for compressed and uncompressed fonts\n");
  fprintf(f_out, "       uint8_t    font_data[];\n");
  fprintf(f_out, "                    // bit field of all characters\n");
  fprintf(f_out, "    }\n");
  fprintf(f_out, "*/\n\n");

  // write target file
  fprintf(f_out, "const uint8_t %s[] PROGMEM = {\n", argv[2]);

  hib = font_size / 256;
  lob = font_size % 256;
  putc_super(f_out, (uint8_t*)&hib, 1);
  fprintf(f_out, ", ");
  putc_super(f_out, (uint8_t*)&lob, 1);
  fprintf(f_out, ", ");
  putc_super(f_out, (uint8_t*)&font_width, 1);
  fprintf(f_out, ", ");
  putc_super(f_out, (uint8_t*)&font_height, 1);
  fprintf(f_out, ", ");
  font_bpp &= 127;  // kill MSB -> no compression
  putc_super(f_out, (uint8_t*)&font_bpp, 1);
  fprintf(f_out, ", ");
  putc_super(f_out, (uint8_t*)&font_First_Char, 1);
  fprintf(f_out, ", ");
  putc_super(f_out, (uint8_t*)&font_Last_Char, 1);
  fprintf(f_out, ",\n");
  putc_super(f_out, (uint8_t*)&font_Char_Width, font_Last_Char - font_First_Char + 1);
  fprintf(f_out, ",\n");
  putc_super(f_out, (uint8_t*)&font_data_out, num_bytesout);
  fprintf(f_out, "};\n");

  printf("\nAll done.\n");

  fclose(f_in);
  fclose(f_out);

  return 0;
}
