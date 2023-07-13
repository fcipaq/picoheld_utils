# Tile map converter for Epic Edit

## Summary

This converts a map created with "Epic Edit" (SNES Mario Kart track editor) to a *pplib* compatible header file.

First thing is to create and export a map with Epic Edit. Then use a text editor of your choice to cut out the `#MAP` part (the rest goes into the trash). Next step is to remove all "#". When done, save the file and use this converter.

Note: The maps are 128 by 128 in size but feel free to create differently sized maps as long as width and height are a power of 2 (e.g. 64 by 32)

## Usage:

`tilemap_conv [input file] [output file] [map width] [map height] [object name]`

## example:

`./tilemap_conv example/tracktiny.hex example/output.h 128 128 example`

output:

```
done.
```

