/*
    created with FontEditor written by H. Reddmann
    HaReddmann at t-online dot de

    File Name           : example/output.h.h
    Font size in bytes  : 0x0c0a, 3082
    Font width          : 17
    Font height         : 16
    Font first char     : 0x0b
    Font last char      : 0xf7
    Font bits per pixel : 1
    Font is compressed  : false

    The font data are defined as

    struct _FONT_ {
     // common shared fields
       uint16_t   font_Size_in_Bytes_over_all_included_Size_it_self;
       uint8_t    font_Width_in_Pixel_for_fixed_drawing;
       uint8_t    font_Height_in_Pixel_for_all_Characters;
       uint8_t    font_Bits_per_Pixels;
                    // if MSB are set then font is a compressed font
       uint8_t    font_First_Char;
       uint8_t    font_Last_Char;
       uint8_t    font_Char_Widths[font_Last_Char - font_First_Char +1];
                    // for each character the separate width in pixels,
                    // characters < 128 have an implicit virtual right empty row
                    // characters with font_Char_Widths[] == 0 are undefined

     // if compressed font then additional fields
       uint8_t    font_Byte_Padding;
                    // each Char in the table are aligned in size to this value
       uint8_t    font_RLE_Table[3];
                    // Run Length Encoding Table for Decompression
       uint8_t    font_Char_Size_in_Bytes[font_Last_Char - font_First_Char +1];
                    // for each char the size in (bytes / font_Byte_Padding) are stored,
                    // this get us the table to seek to the right beginning of each char
                    // in the font_data[]. Withhelp of font_Byte_Padding we ensure that
                    // one byte is suitable to store character sizes greater 255

     // for compressed and uncompressed fonts
       uint8_t    font_data[];
                    // bit field of all characters
    }
*/

const uint8_t pc_senior[] PROGMEM = {
0x0c, 0x0a, 0x11, 0x10, 0x01, 0x0b, 0xf7,
0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x0a, 0x0e, 0x0c, 0x0e, 0x0e, 0x06, 0x08, 0x08, 0x10, 
0x0c, 0x06, 0x0c, 0x04, 0x0e, 0x0e, 0x0c, 0x0c, 0x0c, 0x0e, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x04, 
0x06, 0x0a, 0x0c, 0x0a, 0x0c, 0x0e, 0x0c, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0c, 0x08, 0x0e, 
0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0c, 0x0e, 0x0c, 0x0c, 0x0c, 0x0c, 0x0e, 0x0e, 0x0c, 0x0e, 
0x08, 0x0e, 0x08, 0x0e, 0x10, 0x06, 0x0e, 0x0e, 0x0c, 0x0e, 0x0c, 0x0c, 0x0e, 0x0e, 0x08, 0x0c, 
0x0e, 0x08, 0x0e, 0x0c, 0x0c, 0x0e, 0x0e, 0x0e, 0x0c, 0x0a, 0x0e, 0x0c, 0x0e, 0x0e, 0x0c, 0x0c, 
0x0c, 0x04, 0x0c, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x06, 0x0c, 0x0c, 0x00, 0x0c, 0x10, 0x00, 0x0e, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x0a, 0x10, 0x00, 0x10, 0x00, 
0x10, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x0c, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x0c,
0xf8, 0x1f, 0x08, 0x10, 0xf8, 0x1f, 0x3c, 0x00, 0x3c, 0x00, 0xff, 0x33, 0xff, 0x33, 0xff, 0x33, 
0xff, 0x33, 0x3c, 0x00, 0x3c, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x30, 0x03, 0x30, 0x03, 0xff, 0x3f, 
0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0x30, 0x03, 0x30, 0x03, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 
0xff, 0x3f, 0x30, 0x03, 0x30, 0x03, 0x30, 0x0c, 0x30, 0x0c, 0xfc, 0x0c, 0xfc, 0x0c, 0xcf, 0x3c, 
0xcf, 0x3c, 0xcf, 0x3c, 0xcf, 0x3c, 0xcc, 0x0f, 0xcc, 0x0f, 0x0c, 0x03, 0x0c, 0x03, 0x3c, 0x30, 
0x3c, 0x30, 0x3c, 0x3c, 0x3c, 0x3c, 0x00, 0x0f, 0x00, 0x0f, 0xc0, 0x03, 0xc0, 0x03, 0xf0, 0x00, 
0xf0, 0x00, 0x3c, 0x3c, 0x3c, 0x3c, 0x0c, 0x3c, 0x0c, 0x3c, 0x00, 0x0f, 0x00, 0x0f, 0xcc, 0x3f, 
0xcc, 0x3f, 0xff, 0x30, 0xff, 0x30, 0xf3, 0x33, 0xf3, 0x33, 0x3f, 0x0f, 0x3f, 0x0f, 0xcc, 0x3f, 
0xcc, 0x3f, 0xc0, 0x30, 0xc0, 0x30, 0x30, 0x00, 0x30, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x0f, 0x00, 
0x0f, 0x00, 0xf0, 0x03, 0xf0, 0x03, 0xfc, 0x0f, 0xfc, 0x0f, 0x0f, 0x3c, 0x0f, 0x3c, 0x03, 0x30, 
0x03, 0x30, 0x03, 0x30, 0x03, 0x30, 0x0f, 0x3c, 0x0f, 0x3c, 0xfc, 0x0f, 0xfc, 0x0f, 0xf0, 0x03, 
0xf0, 0x03, 0xc0, 0x00, 0xc0, 0x00, 0xcc, 0x0c, 0xcc, 0x0c, 0xfc, 0x0f, 0xfc, 0x0f, 0xf0, 0x03, 
0xf0, 0x03, 0xf0, 0x03, 0xf0, 0x03, 0xfc, 0x0f, 0xfc, 0x0f, 0xcc, 0x0c, 0xcc, 0x0c, 0xc0, 0x00, 
0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xfc, 0x0f, 0xfc, 0x0f, 0xfc, 0x0f, 
0xfc, 0x0f, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xfc, 
0x00, 0xfc, 0x00, 0x3c, 0x00, 0x3c, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 
0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0x00, 0x3c, 
0x00, 0x3c, 0x00, 0x3c, 0x00, 0x3c, 0x00, 0x3c, 0x00, 0x3c, 0x00, 0x0f, 0x00, 0x0f, 0xc0, 0x03, 
0xc0, 0x03, 0xf0, 0x00, 0xf0, 0x00, 0x3c, 0x00, 0x3c, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x03, 0x00, 
0x03, 0x00, 0xfc, 0x0f, 0xfc, 0x0f, 0xff, 0x3f, 0xff, 0x3f, 0x03, 0x3f, 0x03, 0x3f, 0xc3, 0x33, 
0xc3, 0x33, 0xf3, 0x30, 0xf3, 0x30, 0xff, 0x3f, 0xff, 0x3f, 0xfc, 0x0f, 0xfc, 0x0f, 0x00, 0x30, 
0x00, 0x30, 0x0c, 0x30, 0x0c, 0x30, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0x00, 0x30, 
0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x0c, 0x3c, 0x0c, 0x3c, 0x0f, 0x3f, 0x0f, 0x3f, 0xc3, 0x33, 
0xc3, 0x33, 0xc3, 0x30, 0xc3, 0x30, 0xff, 0x3c, 0xff, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x0c, 0x0c, 
0x0c, 0x0c, 0x0f, 0x3c, 0x0f, 0x3c, 0xc3, 0x30, 0xc3, 0x30, 0xc3, 0x30, 0xc3, 0x30, 0xff, 0x3f, 
0xff, 0x3f, 0x3c, 0x0f, 0x3c, 0x0f, 0xc0, 0x03, 0xc0, 0x03, 0xf0, 0x03, 0xf0, 0x03, 0x3c, 0x03, 
0x3c, 0x03, 0x0f, 0x33, 0x0f, 0x33, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0x00, 0x33, 
0x00, 0x33, 0x3f, 0x0c, 0x3f, 0x0c, 0x3f, 0x3c, 0x3f, 0x3c, 0x33, 0x30, 0x33, 0x30, 0x33, 0x30, 
0x33, 0x30, 0xf3, 0x3f, 0xf3, 0x3f, 0xc3, 0x0f, 0xc3, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xfc, 0x3f, 
0xfc, 0x3f, 0xcf, 0x30, 0xcf, 0x30, 0xc3, 0x30, 0xc3, 0x30, 0xc3, 0x3f, 0xc3, 0x3f, 0x00, 0x0f, 
0x00, 0x0f, 0x0f, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x03, 0x3f, 0x03, 0x3f, 0xc3, 0x3f, 
0xc3, 0x3f, 0xff, 0x00, 0xff, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x3c, 0x0f, 0x3c, 0x0f, 0xff, 0x3f, 
0xff, 0x3f, 0xc3, 0x30, 0xc3, 0x30, 0xc3, 0x30, 0xc3, 0x30, 0xff, 0x3f, 0xff, 0x3f, 0x3c, 0x0f, 
0x3c, 0x0f, 0x3c, 0x00, 0x3c, 0x00, 0xff, 0x30, 0xff, 0x30, 0xc3, 0x30, 0xc3, 0x30, 0xc3, 0x3c, 
0xc3, 0x3c, 0xff, 0x0f, 0xff, 0x0f, 0xfc, 0x03, 0xfc, 0x03, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 
0x3c, 0x3c, 0x00, 0xc0, 0x00, 0xc0, 0x3c, 0xfc, 0x3c, 0xfc, 0x3c, 0x3c, 0x3c, 0x3c, 0xc0, 0x00, 
0xc0, 0x00, 0xf0, 0x03, 0xf0, 0x03, 0x3c, 0x0f, 0x3c, 0x0f, 0x0f, 0x3c, 0x0f, 0x3c, 0x03, 0x30, 
0x03, 0x30, 0x30, 0x0c, 0x30, 0x0c, 0x30, 0x0c, 0x30, 0x0c, 0x30, 0x0c, 0x30, 0x0c, 0x30, 0x0c, 
0x30, 0x0c, 0x30, 0x0c, 0x30, 0x0c, 0x30, 0x0c, 0x30, 0x0c, 0x03, 0x30, 0x03, 0x30, 0x0f, 0x3c, 
0x0f, 0x3c, 0x3c, 0x0f, 0x3c, 0x0f, 0xf0, 0x03, 0xf0, 0x03, 0xc0, 0x00, 0xc0, 0x00, 0x0c, 0x00, 
0x0c, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x03, 0x33, 0x03, 0x33, 0xc3, 0x33, 0xc3, 0x33, 0xff, 0x00, 
0xff, 0x00, 0x3c, 0x00, 0x3c, 0x00, 0xfc, 0x0f, 0xfc, 0x0f, 0xff, 0x3f, 0xff, 0x3f, 0x03, 0x30, 
0x03, 0x30, 0xf3, 0x33, 0xf3, 0x33, 0xf3, 0x33, 0xf3, 0x33, 0xff, 0x03, 0xff, 0x03, 0xfc, 0x03, 
0xfc, 0x03, 0xf0, 0x3f, 0xf0, 0x3f, 0xfc, 0x3f, 0xfc, 0x3f, 0x0f, 0x03, 0x0f, 0x03, 0x0f, 0x03, 
0x0f, 0x03, 0xfc, 0x3f, 0xfc, 0x3f, 0xf0, 0x3f, 0xf0, 0x3f, 0x03, 0x30, 0x03, 0x30, 0xff, 0x3f, 
0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0xc3, 0x30, 0xc3, 0x30, 0xc3, 0x30, 0xc3, 0x30, 0xff, 0x3f, 
0xff, 0x3f, 0x3c, 0x0f, 0x3c, 0x0f, 0xf0, 0x03, 0xf0, 0x03, 0xfc, 0x0f, 0xfc, 0x0f, 0x0f, 0x3c, 
0x0f, 0x3c, 0x03, 0x30, 0x03, 0x30, 0x03, 0x30, 0x03, 0x30, 0x0f, 0x3c, 0x0f, 0x3c, 0x0c, 0x0c, 
0x0c, 0x0c, 0x03, 0x30, 0x03, 0x30, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0x03, 0x30, 
0x03, 0x30, 0x0f, 0x3c, 0x0f, 0x3c, 0xfc, 0x0f, 0xfc, 0x0f, 0xf0, 0x03, 0xf0, 0x03, 0x03, 0x30, 
0x03, 0x30, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0xc3, 0x30, 0xc3, 0x30, 0xf3, 0x33, 
0xf3, 0x33, 0x03, 0x30, 0x03, 0x30, 0x0f, 0x3c, 0x0f, 0x3c, 0x03, 0x30, 0x03, 0x30, 0xff, 0x3f, 
0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0xc3, 0x30, 0xc3, 0x30, 0xf3, 0x03, 0xf3, 0x03, 0x03, 0x00, 
0x03, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0xf0, 0x03, 0xf0, 0x03, 0xfc, 0x0f, 0xfc, 0x0f, 0x0f, 0x3c, 
0x0f, 0x3c, 0x03, 0x30, 0x03, 0x30, 0x03, 0x33, 0x03, 0x33, 0x0f, 0x3f, 0x0f, 0x3f, 0x0c, 0x3f, 
0x0c, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 
0xc0, 0x00, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0x03, 0x30, 0x03, 0x30, 0xff, 0x3f, 
0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0x03, 0x30, 0x03, 0x30, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x3f, 
0x00, 0x3f, 0x00, 0x30, 0x00, 0x30, 0x03, 0x30, 0x03, 0x30, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x0f, 
0xff, 0x0f, 0x03, 0x00, 0x03, 0x00, 0x03, 0x30, 0x03, 0x30, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 
0xff, 0x3f, 0xc0, 0x00, 0xc0, 0x00, 0xf0, 0x03, 0xf0, 0x03, 0x3f, 0x3f, 0x3f, 0x3f, 0x0f, 0x3c, 
0x0f, 0x3c, 0x03, 0x30, 0x03, 0x30, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0x03, 0x30, 
0x03, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x3c, 0x00, 0x3c, 0x00, 0x3f, 0x00, 0x3f, 0xff, 0x3f, 
0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0xfc, 0x00, 0xfc, 0x00, 0xf0, 0x03, 0xf0, 0x03, 0xfc, 0x00, 
0xfc, 0x00, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 
0xff, 0x3f, 0x3c, 0x00, 0x3c, 0x00, 0xf0, 0x00, 0xf0, 0x00, 0xc0, 0x03, 0xc0, 0x03, 0xff, 0x3f, 
0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0xf0, 0x03, 0xf0, 0x03, 0xfc, 0x0f, 0xfc, 0x0f, 0x0f, 0x3c, 
0x0f, 0x3c, 0x03, 0x30, 0x03, 0x30, 0x0f, 0x3c, 0x0f, 0x3c, 0xfc, 0x0f, 0xfc, 0x0f, 0xf0, 0x03, 
0xf0, 0x03, 0x03, 0x30, 0x03, 0x30, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0xc3, 0x30, 
0xc3, 0x30, 0xc3, 0x00, 0xc3, 0x00, 0xff, 0x00, 0xff, 0x00, 0x3c, 0x00, 0x3c, 0x00, 0xfc, 0x03, 
0xfc, 0x03, 0xff, 0x0f, 0xff, 0x0f, 0x03, 0x0c, 0x03, 0x0c, 0x03, 0x3f, 0x03, 0x3f, 0xff, 0x3f, 
0xff, 0x3f, 0xfc, 0x33, 0xfc, 0x33, 0x03, 0x30, 0x03, 0x30, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 
0xff, 0x3f, 0xc3, 0x00, 0xc3, 0x00, 0xc3, 0x03, 0xc3, 0x03, 0xff, 0x3f, 0xff, 0x3f, 0x3c, 0x3c, 
0x3c, 0x3c, 0x3c, 0x0c, 0x3c, 0x0c, 0xff, 0x3c, 0xff, 0x3c, 0xf3, 0x30, 0xf3, 0x30, 0xc3, 0x33, 
0xc3, 0x33, 0x0f, 0x3f, 0x0f, 0x3f, 0x0c, 0x0f, 0x0c, 0x0f, 0x0f, 0x00, 0x0f, 0x00, 0x03, 0x30, 
0x03, 0x30, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0x03, 0x30, 0x03, 0x30, 0x0f, 0x00, 
0x0f, 0x00, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 
0x00, 0x30, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x03, 0xff, 0x03, 0xff, 0x0f, 
0xff, 0x0f, 0x00, 0x3c, 0x00, 0x3c, 0x00, 0x3c, 0x00, 0x3c, 0xff, 0x0f, 0xff, 0x0f, 0xff, 0x03, 
0xff, 0x03, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0x00, 0x0f, 0x00, 0x0f, 0xc0, 0x03, 
0xc0, 0x03, 0x00, 0x0f, 0x00, 0x0f, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0x0f, 0x30, 
0x0f, 0x30, 0x3f, 0x3c, 0x3f, 0x3c, 0xf0, 0x0f, 0xf0, 0x0f, 0xc0, 0x03, 0xc0, 0x03, 0xf0, 0x0f, 
0xf0, 0x0f, 0x3f, 0x3c, 0x3f, 0x3c, 0x0f, 0x30, 0x0f, 0x30, 0x3f, 0x00, 0x3f, 0x00, 0xff, 0x30, 
0xff, 0x30, 0xc0, 0x3f, 0xc0, 0x3f, 0xc0, 0x3f, 0xc0, 0x3f, 0xff, 0x30, 0xff, 0x30, 0x3f, 0x00, 
0x3f, 0x00, 0x3f, 0x30, 0x3f, 0x30, 0x0f, 0x3c, 0x0f, 0x3c, 0x03, 0x3f, 0x03, 0x3f, 0xc3, 0x33, 
0xc3, 0x33, 0xf3, 0x30, 0xf3, 0x30, 0x3f, 0x3c, 0x3f, 0x3c, 0x0f, 0x3f, 0x0f, 0x3f, 0xff, 0x3f, 
0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0x03, 0x30, 0x03, 0x30, 0x03, 0x30, 0x03, 0x30, 0x03, 0x00, 
0x03, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x3c, 0x00, 0x3c, 0x00, 0xf0, 0x00, 0xf0, 0x00, 0xc0, 0x03, 
0xc0, 0x03, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x3c, 0x00, 0x3c, 0x03, 0x30, 0x03, 0x30, 0x03, 0x30, 
0x03, 0x30, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0xc0, 0x00, 0xc0, 0x00, 0xf0, 0x00, 
0xf0, 0x00, 0x3c, 0x00, 0x3c, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x3c, 0x00, 0x3c, 0x00, 0xf0, 0x00, 
0xf0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 
0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 
0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x0f, 0x00, 0x0f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x30, 0x00, 
0x30, 0x00, 0x00, 0x0c, 0x00, 0x0c, 0x30, 0x3f, 0x30, 0x3f, 0x30, 0x33, 0x30, 0x33, 0x30, 0x33, 
0x30, 0x33, 0xf0, 0x0f, 0xf0, 0x0f, 0xc0, 0x3f, 0xc0, 0x3f, 0x00, 0x30, 0x00, 0x30, 0x03, 0x30, 
0x03, 0x30, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x0f, 0xff, 0x0f, 0xc0, 0x30, 0xc0, 0x30, 0xc0, 0x30, 
0xc0, 0x30, 0xc0, 0x3f, 0xc0, 0x3f, 0x00, 0x0f, 0x00, 0x0f, 0xc0, 0x0f, 0xc0, 0x0f, 0xf0, 0x3f, 
0xf0, 0x3f, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0xf0, 0x3c, 0xf0, 0x3c, 0xc0, 0x0c, 
0xc0, 0x0c, 0x00, 0x0f, 0x00, 0x0f, 0xc0, 0x3f, 0xc0, 0x3f, 0xc0, 0x30, 0xc0, 0x30, 0xc3, 0x30, 
0xc3, 0x30, 0xff, 0x0f, 0xff, 0x0f, 0xff, 0x3f, 0xff, 0x3f, 0x00, 0x30, 0x00, 0x30, 0xc0, 0x0f, 
0xc0, 0x0f, 0xf0, 0x3f, 0xf0, 0x3f, 0x30, 0x33, 0x30, 0x33, 0x30, 0x33, 0x30, 0x33, 0xf0, 0x33, 
0xf0, 0x33, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x30, 0xc0, 0x30, 0xfc, 0x3f, 0xfc, 0x3f, 0xff, 0x3f, 
0xff, 0x3f, 0xc3, 0x30, 0xc3, 0x30, 0x0f, 0x00, 0x0f, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0xc0, 0xc3, 
0xc0, 0xc3, 0xf0, 0xcf, 0xf0, 0xcf, 0x30, 0xcc, 0x30, 0xcc, 0x30, 0xcc, 0x30, 0xcc, 0xc0, 0xff, 
0xc0, 0xff, 0xf0, 0x3f, 0xf0, 0x3f, 0x30, 0x00, 0x30, 0x00, 0x03, 0x30, 0x03, 0x30, 0xff, 0x3f, 
0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0xc0, 0x00, 0xc0, 0x00, 0x30, 0x00, 0x30, 0x00, 0xf0, 0x3f, 
0xf0, 0x3f, 0xc0, 0x3f, 0xc0, 0x3f, 0x30, 0x30, 0x30, 0x30, 0xf3, 0x3f, 0xf3, 0x3f, 0xf3, 0x3f, 
0xf3, 0x3f, 0x00, 0x30, 0x00, 0x30, 0x00, 0x3c, 0x00, 0x3c, 0x00, 0xfc, 0x00, 0xfc, 0x00, 0xc0, 
0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0xf3, 0xff, 0xf3, 0xff, 0xf3, 0x3f, 0xf3, 0x3f, 0x03, 0x30, 
0x03, 0x30, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0x00, 0x03, 0x00, 0x03, 0xc0, 0x0f, 
0xc0, 0x0f, 0xf0, 0x3c, 0xf0, 0x3c, 0x30, 0x30, 0x30, 0x30, 0x03, 0x30, 0x03, 0x30, 0xff, 0x3f, 
0xff, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0x00, 0x30, 0x00, 0x30, 0xf0, 0x3f, 0xf0, 0x3f, 0xf0, 0x3f, 
0xf0, 0x3f, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x0f, 0xc0, 0x0f, 0xf0, 0x03, 0xf0, 0x03, 0xf0, 0x3f, 
0xf0, 0x3f, 0xc0, 0x3f, 0xc0, 0x3f, 0xf0, 0x3f, 0xf0, 0x3f, 0xf0, 0x3f, 0xf0, 0x3f, 0x30, 0x00, 
0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0xf0, 0x3f, 0xf0, 0x3f, 0xc0, 0x3f, 0xc0, 0x3f, 0xc0, 0x0f, 
0xc0, 0x0f, 0xf0, 0x3f, 0xf0, 0x3f, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0xf0, 0x3f, 
0xf0, 0x3f, 0xc0, 0x0f, 0xc0, 0x0f, 0x30, 0xc0, 0x30, 0xc0, 0xf0, 0xff, 0xf0, 0xff, 0xc0, 0xff, 
0xc0, 0xff, 0x30, 0xcc, 0x30, 0xcc, 0x30, 0x0c, 0x30, 0x0c, 0xf0, 0x0f, 0xf0, 0x0f, 0xc0, 0x03, 
0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xf0, 0x0f, 0xf0, 0x0f, 0x30, 0x0c, 0x30, 0x0c, 0x30, 0xcc, 
0x30, 0xcc, 0xc0, 0xff, 0xc0, 0xff, 0xf0, 0xff, 0xf0, 0xff, 0x30, 0xc0, 0x30, 0xc0, 0x30, 0x30, 
0x30, 0x30, 0xf0, 0x3f, 0xf0, 0x3f, 0xc0, 0x3f, 0xc0, 0x3f, 0xf0, 0x30, 0xf0, 0x30, 0x30, 0x00, 
0x30, 0x00, 0xf0, 0x03, 0xf0, 0x03, 0xc0, 0x03, 0xc0, 0x03, 0xc0, 0x30, 0xc0, 0x30, 0xf0, 0x33, 
0xf0, 0x33, 0x30, 0x33, 0x30, 0x33, 0x30, 0x33, 0x30, 0x33, 0x30, 0x3f, 0x30, 0x3f, 0x30, 0x0c, 
0x30, 0x0c, 0x30, 0x00, 0x30, 0x00, 0xfc, 0x0f, 0xfc, 0x0f, 0xff, 0x3f, 0xff, 0x3f, 0x30, 0x30, 
0x30, 0x30, 0x30, 0x0c, 0x30, 0x0c, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x3f, 0xf0, 0x3f, 0x00, 0x30, 
0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x3f, 0xf0, 0x3f, 0x00, 0x30, 
0x00, 0x30, 0xf0, 0x03, 0xf0, 0x03, 0xf0, 0x0f, 0xf0, 0x0f, 0x00, 0x3c, 0x00, 0x3c, 0x00, 0x3c, 
0x00, 0x3c, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x03, 0xf0, 0x03, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x3f, 
0xf0, 0x3f, 0x00, 0x3f, 0x00, 0x3f, 0xc0, 0x0f, 0xc0, 0x0f, 0x00, 0x3f, 0x00, 0x3f, 0xf0, 0x3f, 
0xf0, 0x3f, 0xf0, 0x0f, 0xf0, 0x0f, 0x30, 0x30, 0x30, 0x30, 0xf0, 0x3c, 0xf0, 0x3c, 0xc0, 0x0f, 
0xc0, 0x0f, 0x00, 0x03, 0x00, 0x03, 0xc0, 0x0f, 0xc0, 0x0f, 0xf0, 0x3c, 0xf0, 0x3c, 0x30, 0x30, 
0x30, 0x30, 0xf0, 0xc3, 0xf0, 0xc3, 0xf0, 0xcf, 0xf0, 0xcf, 0x00, 0xcc, 0x00, 0xcc, 0x00, 0xcc, 
0x00, 0xcc, 0xf0, 0xff, 0xf0, 0xff, 0xf0, 0x3f, 0xf0, 0x3f, 0xf0, 0x30, 0xf0, 0x30, 0x30, 0x3c, 
0x30, 0x3c, 0x30, 0x3f, 0x30, 0x3f, 0xf0, 0x33, 0xf0, 0x33, 0xf0, 0x30, 0xf0, 0x30, 0x30, 0x3c, 
0x30, 0x3c, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xfc, 0x0f, 0xfc, 0x0f, 0x3f, 0x3f, 
0x3f, 0x3f, 0x03, 0x30, 0x03, 0x30, 0x03, 0x30, 0x03, 0x30, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 
0x3f, 0x3f, 0x03, 0x30, 0x03, 0x30, 0x03, 0x30, 0x03, 0x30, 0x3f, 0x3f, 0x3f, 0x3f, 0xfc, 0x0f, 
0xfc, 0x0f, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0f, 0x00, 
0x0f, 0x00, 0x03, 0x00, 0x03, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0f, 0x00, 
0x0f, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 
0x0f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x3f, 0x00, 
0x3f, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 
0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x00, 
0x3f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 
0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 
0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 
0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xfc, 0x00, 
0xfc, 0x00, 0xff, 0x03, 0xff, 0x03, 0xff, 0x0f, 0xff, 0x0f, 0xfc, 0x3f, 0xfc, 0x3f, 0xff, 0x0f, 
0xff, 0x0f, 0xff, 0x03, 0xff, 0x03, 0xfc, 0x00, 0xfc, 0x00, 0xc0, 0x3c, 0xc0, 0x3c, 0xfc, 0x3f, 
0xfc, 0x3f, 0xff, 0x3f, 0xff, 0x3f, 0xc3, 0x30, 0xc3, 0x30, 0x0f, 0x30, 0x0f, 0x30, 0x3c, 0x3c, 
0x3c, 0x3c, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x00, 0x30, 0x00, 0x30, 0xcc, 0xf3, 
0xcc, 0xf3, 0xff, 0xcf, 0xff, 0xcf, 0x33, 0xcc, 0x33, 0xcc, 0xf3, 0xff, 0xf3, 0xff, 0xc3, 0x33, 
0xc3, 0x33, 0x0f, 0x00, 0x0f, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0xfc, 0x3f, 0xfc, 0x3f, 0x03, 0xc0, 
0x03, 0xc0, 0x33, 0xc3, 0x33, 0xc3, 0x03, 0xcf, 0x03, 0xcf, 0x03, 0xcf, 0x03, 0xcf, 0x33, 0xc3, 
0x33, 0xc3, 0x03, 0xc0, 0x03, 0xc0, 0xfc, 0x3f, 0xfc, 0x3f, 0xc0, 0x00, 0xc0, 0x00, 0xf0, 0x03, 
0xf0, 0x03, 0x3c, 0x0f, 0x3c, 0x0f, 0x0c, 0x0c, 0x0c, 0x0c, 0xc0, 0x00, 0xc0, 0x00, 0xf0, 0x03, 
0xf0, 0x03, 0x3c, 0x0f, 0x3c, 0x0f, 0x0c, 0x0c, 0x0c, 0x0c, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 
0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 
0xc0, 0x00, 0x00, 0xc0, 0x00, 0xc0, 0xfc, 0xff, 0xfc, 0xff, 0xfc, 0x3f, 0xfc, 0x3f, 0x00, 0x0c, 
0x00, 0x0c, 0x00, 0x0c, 0x00, 0x0c, 0xfc, 0x0f, 0xfc, 0x0f, 0xfc, 0x03, 0xfc, 0x03, 0x0c, 0x0c, 
0x0c, 0x0c, 0x3c, 0x0f, 0x3c, 0x0f, 0xf0, 0x03, 0xf0, 0x03, 0xc0, 0x00, 0xc0, 0x00, 0x0c, 0x0c, 
0x0c, 0x0c, 0x3c, 0x0f, 0x3c, 0x0f, 0xf0, 0x03, 0xf0, 0x03, 0xc0, 0x00, 0xc0, 0x00, 0xc3, 0x3f, 
0xc3, 0x3f, 0xf3, 0x3f, 0xf3, 0x3f, 0x3c, 0x03, 0x3c, 0x03, 0x0c, 0x03, 0x0c, 0x03, 0x3c, 0x03, 
0x3c, 0x03, 0xf3, 0x3f, 0xf3, 0x3f, 0xc3, 0x3f, 0xc3, 0x3f, 0x03, 0x00, 0x03, 0x00, 0xc3, 0x03, 
0xc3, 0x03, 0xf0, 0x0f, 0xf0, 0x0f, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0xf0, 0x0f, 
0xf0, 0x0f, 0xc3, 0x03, 0xc3, 0x03, 0x03, 0x00, 0x03, 0x00, 0xf3, 0x0f, 0xf3, 0x0f, 0xf3, 0x3f, 
0xf3, 0x3f, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0x00, 0x30, 0xf3, 0x3f, 0xf3, 0x3f, 0xf3, 0x0f, 
0xf3, 0x0f, 0xf0, 0xff, 0xf0, 0xff, 0xfc, 0xff, 0xfc, 0xff, 0xcc, 0x0c, 0xcc, 0x0c, 0xcc, 0x0c, 
0xcc, 0x0c, 0xfc, 0x0f, 0xfc, 0x0f, 0x30, 0x03, 0x30, 0x03, 0x03, 0x0c, 0x03, 0x0c, 0x33, 0x3f, 
0x33, 0x3f, 0x30, 0x33, 0x30, 0x33, 0x30, 0x33, 0x30, 0x33, 0xf3, 0x3f, 0xf3, 0x3f, 0xc3, 0x3f, 
0xc3, 0x3f, 0x00, 0x30, 0x00, 0x30, 0x0c, 0x0f, 0x0c, 0x0f, 0xcc, 0x3f, 0xcc, 0x3f, 0xc0, 0x30, 
0xc0, 0x30, 0xc0, 0x30, 0xc0, 0x30, 0xcc, 0x3f, 0xcc, 0x3f, 0x0c, 0x0f, 0x0c, 0x0f, 0xc0, 0x00, 
0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xcf, 0x3c, 0xcf, 0x3c, 0xcf, 0x3c, 0xcf, 0x3c, 0xc0, 0x00, 
0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00};
