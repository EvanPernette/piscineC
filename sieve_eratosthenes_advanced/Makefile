CC = gcc

CFLAGS= -std=c99 -Wall -Wextra -Werror -pedantic -Wvla

all: sieve.o

sieve.o: sieve.c
	${CC} ${CFLAGS} -c sieve.c -o sieve.o


clean:
	rm -f *.o
	rm -f sieve
