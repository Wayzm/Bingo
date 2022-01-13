CC=gcc
OMP=fopenmp

main.o: main.c
	$(CC) main.c -o main -$(OMP)

run:
	./main

clean:
	rm *.o
