CC = gcc
CFLAGS = -fPIC -Wall -Wextra -Werror -pedantic -std=c99 -g

SRC = binary.c
OBJS = $(SRC:.c=.o)
LIB = libbinary_tree.a

all: library

library: $(LIB)
$(LIB): $(OBJS)
	ar crs $@ $^

clean:
	$(RM) *.o *.a
