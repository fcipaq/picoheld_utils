# Bitmap converter 8 bits to 256 colors

## Summary

This converts a 8 bit bitmap to a *pplib* compatible header file also exporting the palette to the header file.

Note: Since a bitmap is stored "upside down" the bitmap needs to be flipped vertically before conversion.

## Usage:

`bmpconv_8_8 [input file] [output file] [object name]`

## example:

`./bmpconv_8_8 example/car8.bmp example/output.h example`

output:

```
Found BMP header.
Image width:      128
Image height:     256
No. of colors:    114

done.
```

