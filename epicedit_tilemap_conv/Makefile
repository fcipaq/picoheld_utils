default: tilemap_conv

tilemap_conv.o: main.c
	gcc -c main.c -o tilemap_conv.o

tilemap_conv: tilemap_conv.o
	gcc tilemap_conv.o -o tilemap_conv

clean:
	-rm -f tilemap_conv.o
	-rm -f tilemap_conv
    
