CC=gcc
OMP=fopenmp

main.o: main.c
	$(CC) main.c Tools.c -o main -$(OMP)

run:
	./main

clean:
	rm *.o
