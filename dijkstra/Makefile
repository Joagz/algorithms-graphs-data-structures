all: .\build\dijkstra.o

exe: .\dijkstra.o .\build\node.o
	gcc .\dijkstra.o .\build\node.o -I./ -I./include -o .\bin\dijkstra.exe -DDEBUG

.\build\node.o: .\node.h
	gcc -c .\node.c -I.\ -I.\include -o .\build\node.o 

.\build\dijkstra.o: .\dijkstra.c
	gcc .\dijkstra.c -I.\ -I.\include -o .\build\dijkstra.o

# For windows
clean:
	del .\build\dijkstra.o
	del .\build\node.o
	del .\bin\dijkstra.exe


