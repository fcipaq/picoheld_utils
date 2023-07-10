default: fontdecompressor

fontdecompressor.o: main.c
	gcc -c main.c -o fontdecompressor.o

fontdecompressor: fontdecompressor.o
	gcc fontdecompressor.o -o fontdecompressor

clean:
	-rm -f fontdecompressor.o
	-rm -f fontdecompressor
    
