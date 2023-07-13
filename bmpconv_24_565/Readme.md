# Bitmap converter 24 bits to 16 bits

## Summary

This converts a 24 bit bitmap to a *pplib* compatible header in 16 bit format. 

Note: Since a bitmap is stored "upside down" the bitmap needs to be flipped vertically before conversion.

## Usage:

`bmpconv_24_565 [input file] [output file] [object name]`

## example:

`./bmpconv_24_565 example/car.bmp example/output.h example`

output:

```
data size is  :  98358 bytes
image width is:  128
image height is: 256
color depth is:  24 bits

done.
```

