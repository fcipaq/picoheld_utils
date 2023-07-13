# Bitmap converter 24 bits to 256 colors

## Summary

This converts a 24 bit bitmap to a *pplib* compatible header file using the standard 332 palette (i.e. 8 -> 3, 8 -> 3, 8 -> 2 bit)

Note: Since a bitmap is stored "upside down" the bitmap needs to be flipped vertically before conversion.

## Usage:

`bmpconv_24_8 [input file] [output file] [object name]`

## example:

`./bmpconv_24_8 example/car.bmp example/output.h example`

output:

```
filesize is   :  98358 bytes
image width is:  128
image height is: 256
color depth is:  24 bits
standard palette output

done.
```

