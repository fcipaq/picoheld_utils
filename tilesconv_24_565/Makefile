default: tilesconv_24_565

tilesconv_24_565.o: main.c
	gcc -c main.c -o tilesconv_24_565.o

tilesconv_24_565: tilesconv_24_565.o
	gcc tilesconv_24_565.o -o tilesconv_24_565

clean:
	-rm -f tilesconv_24_565.o
	-rm -f tilesconv_24_565
    
