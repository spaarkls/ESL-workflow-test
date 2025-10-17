CC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra


all: vector.out

vector.out: main.o vector3D.o
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.c
	$(CC) -c $(CFLAGS) main.c -o $@

vector3D.o: vector/vector3D.c vector/vector3D.h
	$(CC) -c $(CFLAGS) vector/vector3D.c -o $@


clean:
	rm -rf *.o *.out