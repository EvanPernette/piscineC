CC = gcc

CFLAGS = -std=c99 -Wall -Wextra -Werror -pedantic -Wvla

all : libvector

libvector : vector.o
	ar csr libvector.a vector.o

vector.o: vector.c
	$(CC) $(CFLAGS) -o vector.o -c vector.c

clean : rm -f *.a rm -f libvector
