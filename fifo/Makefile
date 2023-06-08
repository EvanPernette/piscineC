CC = gcc
CFLAGS = -fPIC -Wall -Wextra -Werror -pedantic -std=c99 -g

SRC = fifo_access.c fifo_setup_destroy.c
OBJS = $(SRC:.c=.o)
LIB = libfifo.a

all: library

library: $(LIB)
$(LIB): $(OBJS)
	ar crs $@ $^

clean:
	$(RM) *.o *.a
