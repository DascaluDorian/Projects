CC=gcc
CFLAGS=-I.
DEPS = singly_functions.h doubly_functions.h
OBJ = main.o functions.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

LinkedLists: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)