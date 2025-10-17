CC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra
LIBS = -lcheck -lm -lsubunit
BUILD_DIR = build

.PHONY: all clean test

all: test

test: main.o libvector3D.a
	$(CC) $(CFLAGS) $(BUILD_DIR)/main.o -L$(BUILD_DIR) -lvector3D -o tests $(LIBS)

libvector3D.a: vector3D.o
	ar rcs $@ $^
	mkdir -p $(BUILD_DIR) && mv *.o $(BUILD_DIR)/ && mv *.a $(BUILD_DIR)/ 


vector3D.o: vector/vector3D.c vector/vector3D.h
	$(CC) -c $(CFLAGS) vector/vector3D.c -o $@

main.o: main.c
	$(CC) -c $(CFLAGS) $^ -o $@ 


clean:
	rm -rf build/* tests