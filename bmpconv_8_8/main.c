#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

uint16_t RGBColor565(uint8_t r, uint8_t g, uint8_t b) {
  r = r >> 3;
  g = g >> 2;
  b = b >> 3;

  return (r << 11) + (g << 5) + b;
}

enum BMPHeader_e {
  // word = 16 bits
  // dword = 32 bits
  BMP_signature,         // must be 0x4D42
  BMP_bmpsize = 2,       // size of BMP file in bytes (unreliable)
  BMP_reserved1 = 6,     // must be zero
  BMP_reserved2 = 8,     // must be zero
  BMP_ofsimgdata = 10,   // offset to start of image data in bytes
  BMP_headersize = 14,   // size of BITMAPINFOHEADER structure, must be 40
  BMP_width = 18,        // image width in pixels
  BMP_height = 22,       // image height in pixels
  BMP_planes = 26,       // # of planes, must be 1
  BMP_coldepth = 28,     // bpp 1, 4, 8 or 24
  BMP_compression = 30,  // 0 = none, 1 = RLE-8, 2 =RLE-4
  BMP_filesize = 34,     // size of image data in bytes (incl. padding)
  BMP_dpmeterx = 38,     // horiz. res. in pixel per meter (unreliable)
  BMP_dpmetery = 42,     // vert. res. in pixel per meter (unreliable)
  BMP_numcol = 46,       // # of colors or zero
  BMP_numimpcol = 50,    // number of important colors or zero
  BMP_size = 54
};

uint32_t getvalue(uint32_t* b, int n) {
  uint32_t tmp;
  memcpy(&tmp, b, n);
  return tmp;
}

int main(int argc, char** argv) {

  if (argc != 4) {
    printf("Please state one input and one output file followed by the object name.\n");
    return -1;
  }

  if (sizeof(uint32_t) != 4 || sizeof(uint16_t) != 2) {
    printf("Type size incorrect. Please recompile.\n");
    return -1;
  }

  FILE* f_in = fopen(argv[1], "rb");
  FILE* f_out = fopen(argv[2], "w");

  uint8_t b[100];
  uint8_t objname[100];
  uint8_t bmpHeader[BMP_size];
  uint16_t c;
  uint16_t x, y;
  uint32_t bmp_width;
  uint32_t bmp_height;

  uint8_t padding = 0;
  uint32_t wr_count = 0;

  sscanf(argv[3], "%99s", objname);

  fread(bmpHeader, 1, 54, f_in);

  int numcol = getvalue((uint32_t*)&bmpHeader[BMP_numcol], 4);

  if (getvalue((uint32_t*)&bmpHeader[BMP_coldepth], 2) != 8) {
    printf("Colordepth must be 8 bits.\n");
    goto bailout;
  }

  if (getvalue((uint32_t*)&bmpHeader[BMP_headersize], 4) != 40) {
    printf("Expected header size of exactly 40 bytes.\n");
    goto bailout;
  }

  bmp_width = getvalue((uint32_t*)&bmpHeader[BMP_width], 4);
  bmp_height = getvalue((uint32_t*)&bmpHeader[BMP_height], 4);

  // The color palette is located directly after the header. BMP_numcol states the number of
  // used colors. Any color has four bytes: 3 bytes color info + 1 byte alpha
  
  printf("Found BMP header.\n");
  printf("Image width:      %d\n", bmp_width);
  printf("Image height:     %d\n", bmp_height);
  printf("No. of colors:    %d\n", numcol);

  fprintf(f_out, "color_palette_t %s_palette[%d] = {\n", objname, numcol);

  for (uint32_t col_i = 0; col_i < numcol; col_i++) {
    fread(b, 1, 4, f_in);
    fprintf(f_out, "  0x%04x", RGBColor565(b[2], b[1], b[0]));
    //fprintf(f_out, "  rgb_col_888_565(0x%02x, 0x%02x, 0x%02x)", b[0], b[1], b[2]);

    if (col_i != numcol - 1)
      fprintf(f_out, ",\n");
    else
      fprintf(f_out, "\n");
      
  }
  
  fprintf(f_out, "};\n\n");

  //padding = (getvalue((uint32_t*) &bmpHeader[BMP_filesize], 4) - bmp_width * bmp_height * 1) / bmp_height;

  fprintf(f_out, "const uint8_t %s_data[] PROGMEM = {\n ", objname);

  for (uint32_t y = 0; y < getvalue((uint32_t*)&bmpHeader[BMP_height], 4); y++) {
    for (uint32_t x = 0; x < getvalue((uint32_t*)&bmpHeader[BMP_width], 4); x++) {

      b[0] = fgetc(f_in);

      fprintf(f_out, " 0x%02x", b[0]);

      wr_count++;

      if (wr_count < bmp_width * bmp_height)
        fprintf(f_out, ",");

      if ((wr_count % 16 == 0) && !((x == bmp_width - 1) && (y == bmp_height - 1)))
        fprintf(f_out, "\n ");
        
    }

    for (int h = 0; h < padding; h++)
      b[0] = fgetc(f_in);
      
  }

  fprintf(f_out, "\n};\n\n");

  fprintf(f_out, "gbuffer8_t %s = {\n", objname);
  fprintf(f_out, "  8,\n");  // 8 bits
  fprintf(f_out, "  %d,\n", bmp_width);
  fprintf(f_out, "  %d,\n", bmp_height);
  fprintf(f_out, "  (uint8_t*) %s_data\n", objname);
  fprintf(f_out, "};\n");

  printf("\ndone.\n\n");

bailout:

  fclose(f_in);
  fclose(f_out);

  return 0;
}
