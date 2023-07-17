/*
 * Utilities for the pplib - a library for the PicoPal handheld
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
#include <stdlib.h>
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

  uint8_t b[100];
  uint8_t objname[100];
  uint8_t bmpHeader[BMP_size];
  uint32_t bmp_width;
  uint32_t bmp_height;
  uint32_t bmp_datasize;
  uint32_t c;
  uint32_t x, y;
  uint32_t padding;
  uint32_t tiles_num;
  uint32_t tiles_width;
  uint32_t tiles_height;
  uint16_t* filebuffer;
  uint32_t datasize;
  uint32_t wr_count = 0;
  
  if (argc != 6) {
    printf("Please state one input and one output file followed by tile width and tile height and tile object name.\n");
    return -1;
  }

  if (sizeof(uint32_t) != 4 || sizeof(uint16_t) != 2) {
    printf("Type size incorrect. Please recompile.\n");
    return -1;
  }

  FILE* f_in = fopen(argv[1], "rb");
  FILE* f_out = fopen(argv[2], "w");

  sscanf(argv[3], "%d", &tiles_width);
  sscanf(argv[4], "%d", &tiles_height);
  sscanf(argv[5], "%99s", objname);

  fread(bmpHeader, 1, 54, f_in);

  if (getvalue((uint32_t*)&bmpHeader[BMP_coldepth], 2) != 24) {  //coldepth
    printf("Colordepth must be 24 bits.\n");
    goto bailout;
  }

  bmp_width = getvalue((uint32_t*)&bmpHeader[BMP_width], 4);
  bmp_height = getvalue((uint32_t*)&bmpHeader[BMP_height], 4);
  bmp_datasize = getvalue((uint32_t*)&bmpHeader[BMP_datasize], 4);
  
  //      b[h] = fgetc(f_in);
  //    read(f_in, &b, getvalue((uint32_t*) &bmpHeader[BMP_ofsimgdata], 4) - 54);

  if (bmp_datasize)
    padding = (bmp_datasize - bmp_width * bmp_height * 3) / bmp_height;
  else
    padding = 0;

  datasize = bmp_width * bmp_height * 3;

  tiles_num = bmp_width * bmp_height / (tiles_width * tiles_height);

  printf("data size is:     %d bytes\n", datasize);
  printf("image width is:   %d\n", bmp_width);
  printf("image height is:  %d\n", bmp_height);
  printf("image padding is: %d\n", padding);
  printf("tiles width is:   %d\n", tiles_width);
  printf("tiles height is:  %d\n", tiles_height);
  printf("# of tiles:       %d\n", tiles_num);

  // make file buffer
  filebuffer = (uint16_t*)malloc(datasize * 2);

  for (uint32_t y = 0; y < bmp_height; y++) {
    for (uint32_t x = 0; x < bmp_width; x++) {
      fread(b, 1, 3, f_in);

      c = RGBColor565(b[2], b[1], b[0]);
      
      uint32_t y_inv = bmp_height - y - 1;

      filebuffer[((x / tiles_width) + (y_inv / tiles_height) * (bmp_width / tiles_width)) * (tiles_width * tiles_height) +  // ofs to tile
                 (y_inv % tiles_height) * tiles_width + x % tiles_width] = c;                                               // within tile
    }
    for (int h = 0; h < padding; h++)
      b[0] = fgetc(f_in);
  }

  // write loop
  wr_count = 0;

  fprintf(f_out, "const uint16_t %s_tile_image_data_raw[] PROGMEM = {\n ", objname);

  for (uint32_t n = 0; n < tiles_num * tiles_width * tiles_height; n++) {
    fprintf(f_out, " 0x%04x", filebuffer[n]);

    if (n < (tiles_num * tiles_width * tiles_height - 1)) {
      fprintf(f_out, ",");

      wr_count++;
      if ((n + 1) % tiles_width == 0) {
        fprintf(f_out, "\n ");
        wr_count = 0;
      }
      if ((n + 1) % (tiles_width * tiles_height) == 0) {
        fprintf(f_out, "\n ");
        wr_count = 0;
      }

      if (wr_count == 16) {
        wr_count = 0;
        fprintf(f_out, "\n ");
      }

    }

  }

  fprintf(f_out, "\n};\n\n");

  fprintf(f_out, "gbuffer16_t %s_tile_image_data = {\n", objname);
  fprintf(f_out, "  16,  // bpp\n");
  fprintf(f_out, "  %d,  // width\n", bmp_width);
  fprintf(f_out, "  %d,  // height\n", bmp_height);
  fprintf(f_out, "  (uint16_t*) %s_tile_image_data_raw\n", objname);
  fprintf(f_out, "};\n\n");

  fprintf(f_out, "tile_data_t %s = {\n", objname);
  fprintf(f_out, "  %d,  // tile width\n", tiles_width);
  fprintf(f_out, "  %d,  // tile height\n", tiles_height);
  fprintf(f_out, "  %d,  // # of tiles\n", tiles_num);
  fprintf(f_out, "  &%s_tile_image_data\n", objname);
  fprintf(f_out, "};\n");


  printf("done.\n\n");

bailout:

  fflush(f_out);
  fclose(f_in);
  fclose(f_out);
  free(filebuffer);

  return 0;
}
