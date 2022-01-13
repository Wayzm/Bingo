CC=gcc

main.o: main.c
	$(CC) -c main.c

run:
	./main

clean:
	rm *.o
