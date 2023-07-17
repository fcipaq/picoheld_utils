/*
 * Utilities for the pplib - a library for the Pico Held handheld
 *
 * Copyright (C) 2023 Daniel Kammer (daniel.kammer@web.de)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

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
  // word = 2 bytes unsigned int
  // dword = 4 bytes unsigned int
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
  BMP_datasize = 34,     // size of image data in bytes (incl. padding)
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
  uint8_t bmp_col;
  uint8_t padding;
  uint8_t offset = 0;
  uint32_t wr_count = 0;

  sscanf(argv[3], "%99s", objname);

  fread(bmpHeader, 1, 54, f_in);

  bmp_col = getvalue((uint32_t*)&bmpHeader[BMP_coldepth], 2);

  if (bmp_col != 24) {  //coldepth
    printf("Colordepth must be 24 bits.\n");
    goto bailout;
  }

  for (int h = 0; h < getvalue((uint32_t*)&bmpHeader[BMP_ofsimgdata], 4) - 54; h++)
    b[h] = fgetc(f_in);

  bmp_width = getvalue((uint32_t*)&bmpHeader[BMP_width], 4);
  bmp_height = getvalue((uint32_t*)&bmpHeader[BMP_height], 4);

  padding = (getvalue((uint32_t*)&bmpHeader[BMP_datasize], 4) - bmp_width * bmp_height * 3) / bmp_height;

  printf("data size is  :  %d bytes\n", getvalue((uint32_t*)&bmpHeader[BMP_datasize], 4) + 54);
  printf("image width is:  %d\n", bmp_width);
  printf("image height is: %d\n", bmp_height);
  printf("color depth is:  %d bits\n", bmp_col);

  fprintf(f_out, "const uint16_t %s_data[] PROGMEM = {\n ", objname);

  for (uint32_t y = 0; y < bmp_height; y++) {
    for (uint32_t x = 0; x < bmp_width; x++) {
      
      fread(b, 1, 3, f_in);

      c = RGBColor565(b[2], b[1], b[0]);
      
      fprintf(f_out, " 0x%04x", c);
      
      wr_count++;
            
      if (wr_count < bmp_height * bmp_width)
        fprintf(f_out, ",");
		    
      if ((wr_count % 16 == 0) && !((x == bmp_width - 1) && (y == bmp_height - 1)))
        fprintf(f_out, "\n ");	  
      
    }

    for (int h = 0; h < padding; h++)
      b[0] = fgetc(f_in);
  }

  fprintf(f_out, "\n};\n\n");
    
  fprintf(f_out, "gbuffer16_t %s = {\n", objname);
  fprintf(f_out, "  16,\n");  // 16 bits
  fprintf(f_out, "  %d,\n", bmp_width);
  fprintf(f_out, "  %d,\n", bmp_height);
  fprintf(f_out, "  (uint16_t*) %s_data\n", objname);
  fprintf(f_out, "};\n");

  printf("\ndone.\n\n");
    
bailout:

  fclose(f_in);
  fclose(f_out);

  return 0;
}
