default: bmpconv_8_8

bmpconv_8_8.o: main.c
	gcc -c main.c -o bmpconv_8_8.o

bmpconv_8_8: bmpconv_8_8.o
	gcc bmpconv_8_8.o -o bmpconv_8_8

clean:
	-rm -f bmpconv_8_8.o
	-rm -f bmpconv_8_8
    
