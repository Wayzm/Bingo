CC=gcc
OMP=fopenmp

run: main.o
	./main.o

main.o: main.c
	$(CC) main.c Tools.c -o main.o -$(OMP)


clean:
	rm *.o
