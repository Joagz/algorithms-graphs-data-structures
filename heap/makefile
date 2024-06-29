all: .\build\heap.o

.\bin\heap.exe: .\heap.c
	gcc .\heap.c -I.\ -o ./bin/heap.exe -DDEBUG


./build/heap.o: ./heap.c
	gcc -c .\heap.c -I.\ -o ./build/heap.o