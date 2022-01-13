CC=gcc

main.o: main.c
	$(CC) main.c -o main

run:
	./main

clean:
	rm *.o
