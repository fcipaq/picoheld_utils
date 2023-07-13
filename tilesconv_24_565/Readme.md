# Tile converter 24 bits to 565 (16 bits)

## Summary

This converts a 128 by 128 tile set of 24 tiles (3 empty) to a header file.

The tiles may be arranged as an "array" or a single strip. The converter will determine how many tiles there are in row (using the tile dimensions provided) and will enumerate them like reading a book (line by line and from left to right).

The input file needs to be a 24 bit bitmap which then is converted to 16 bits.

## Usage:

`tilesconv_24_565 [input file] [output file] [tile width] [tile height] [object name]`

## example:

`./tilesconv_24_565 example/tiles16.bmp example/output.h 128 128 example`

output:

```
data size is:     1179648 bytes
image width is:   1024
image height is:  384
image padding is: 0
tiles width is:   128
tiles height is:  128
# of tiles:       24
done.
```

