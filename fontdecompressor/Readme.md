# Font decompressor

## Summary

This converts a compressed FONT file to a pplib compatible header file

You may convert TTF fonts to the FONT format using a tool by H. Reddmann which you can find [here](https://www.mikrocontroller.net/topic/99701?goto=865331#865331).

Note: Font compression is mandatory.

## Usage:

`fontdecompressor [input file] [output file] [object name] [optional: ascii art]`

## example:

`./fontdecompressor example/pc_senior.font example/output.h pc_senior`

output:

```
This converter decompresses .font files and converts them to.
be used with the Pico Hero library.

font size is:    2630 bytes
font width is:   17 pixels
font height is:  16 pixels
font 1st char:   11
font lst char:   247
byte padding:    1
header size is:  485 bytes
Decompression complete.
Saving font file.

All done.
```

