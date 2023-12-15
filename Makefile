CFLAGS = -lm -Wall -Wextra

.PHONY: all clean run
all: main

main: main.o funcs.o
	gcc $(CFLAGS) -o main main.o funcs.o

main.o: main.c 
	gcc $(CFLAGS) -c main.c 

funcs.o: funcs.c 
	gcc $(CFLAGS) -c funcs.c

clean:
	rm -f main *.o

run: main
	./main 
