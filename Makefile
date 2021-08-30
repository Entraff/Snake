.SUFFIXES:

CC = clang
CFLAGS = -std=c11 -O2 -g -Wall -Wextra -Wpedantic -Wstrict-aliasing \
		 -Wno-pointer-arith -Wno-newline-eof -Wno-unused-parameter -Wno-gnu-statement-expression \
		 -Wno-gnu-compound-literal-initializer -Wno-gnu-zero-variadic-macro-arguments
LDFLAGS = -lncurses -ltinfo

TARGET = snake
SRC = $(wildcard ./src/*.c ./src/**/*.c)
OBJS = $(SRC:.c=.o)

all: $(TARGET) clean

$(TARGET): $(OBJS) 
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm $(OBJS)
