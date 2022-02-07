CC=gcc
OMP=fopenmp

main.o: main.c
	$(CC) main.c Tools.c -o main.o -$(OMP)

run:
	./main.o

clean:
	rm *.o
