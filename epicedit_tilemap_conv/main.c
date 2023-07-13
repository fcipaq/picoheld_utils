/*
 * Utilities for the pplib - a library for the Pico Hero handheld
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

int main(int argc, char** argv) {

  if (argc != 6) {
    printf("Please state one input and one output file followed by the width and height of the map and the name of the tile map object.\n");
    return -1;
  }

  FILE* f_in = fopen(argv[1], "rb");
  FILE* f_out = fopen(argv[2], "w");

  uint8_t b[100];
  uint8_t objname[100];

  uint16_t c;
  uint16_t x, y;
  uint32_t map_width, map_height;
  uint32_t map_width_ext, map_height_ext;

  sscanf(argv[3], "%d", &map_width);
  sscanf(argv[4], "%d", &map_height);

  sscanf(argv[5], "%99s", objname);


  fprintf(f_out, "const uint8_t %s_data[] PROGMEM = {\n", objname);
  map_width_ext = map_width * 2;
  map_height_ext = map_height * 2;

#ifdef EXPAND_MAP
   // upper frame
  for (int i = 0; i < map_height / 2; i++) {
    for (int h = 0; h < map_width * 2; h++) {
      fprintf(f_out, "0xXX");
      if (i != (map_height / 2 - 1) || h != (map_width * 2 - 1))
        fprintf(f_out, ", ");
    }
    fprintf(f_out, "\n");
  }
#endif

  // actual image
  for (uint32_t y = 0; y < map_height; y++) {

#ifdef EXPAND_MAP
    // left frame
    for (int h = 0; h < map_width / 2; h++)
      fprintf(f_out, "0xXX, ");
#endif

    for (uint32_t x = 0; x < map_width; x++) {
      if (fread(b, 1, 1, f_in) != 1) {
        printf("\n\nERROR reading source file!\n");
        goto bailout;
      }
      fprintf(f_out, "0x%02x, ", b[0]);
    }

#ifdef EXPAND_MAP
    // right frame
    for (int h = 0; h < map_width / 2; h++)
      fprintf(f_out, "0xXX, ");
#endif

    fprintf(f_out, "\n");
  }

#ifdef EXPAND_MAP
  // lower frame
  for (int i = 0; i < map_height / 2; i++) {
    for (int h = 0; h < map_width * 2; h++) {
      fprintf(f_out, "0xXX");
      if (i != (map_height / 2 - 1) || h != (map_width * 2 - 1))
        fprintf(f_out, ", ");
    }
    fprintf(f_out, "\n");
  }
#endif

  fprintf(f_out, "};\n\n");


  fprintf(f_out, "tile_map_t %s = {\n", objname);
  fprintf(f_out, "  %d,\n", map_width_ext);
  fprintf(f_out, "  %d,\n", map_height_ext);
  fprintf(f_out, "  (uint8_t*) %s_data\n", objname);
  fprintf(f_out, "};");

  printf("done.\n");

bailout:

  fclose(f_in);
  fclose(f_out);

  return 0;
}
