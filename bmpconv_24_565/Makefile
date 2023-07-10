default: bmpconv_24_565

bmpconv_24_565.o: main.c
	gcc -c main.c -o bmpconv_24_565.o

bmpconv_24_565: bmpconv_24_565.o
	gcc bmpconv_24_565.o -o bmpconv_24_565

clean:
	-rm -f bmpconv_24_565.o
	-rm -f bmpconv_24_565
    
