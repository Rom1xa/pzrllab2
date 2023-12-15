CFLAGS = -Wall -Wextra

.PHONY: all clean run
all: main

main: main.o
	gcc $(CFLAGS) -o main.o

main.o: main.c 
	gcc $(CFLAGS) -c main.c 

clean:
	rm -f main *.o

run: main
	./main 
