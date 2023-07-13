# Tile converter 8 bits to 256 colors

## Summary

This converts a 128 by 128 tile set of 24 tiles (3 empty) to a header file.

The tiles may be arranged as an "array" or a single strip. The converter will determine how many tiles there are in row (using the tile dimensions provided) and will enumerate them like reading a book (line by line and from left to right).

The input file needs to be an 8 bit bitmap which then is converted and the palette is exported to the header file.

## Usage:

`tilesconv_8_8 [input file] [output file] [tile width] [tile height] [object name]`

## example:

`./tilesconv_8_8 example/tiles8.bmp example/output.h 128 128 example`

output:

```
Found BMP header.
image width is:   128
image height is:  2944
No. of tiles:     23
data size is:     0
No. of colors:    256
image padding is: 0
done.
```

