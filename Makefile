CC ?= gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99 -Iinclude -O2
SRC = src/loading_screen.c
OBJ = $(SRC:.c=.o)
EXAMPLE_SRC = examples/demo.c

ifeq ($(OS),Windows_NT)
    TARGET = loading_demo.exe
    RM = del /Q
else
    TARGET = loading_demo
    RM = rm -f
endif

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(OBJ) $(EXAMPLE_SRC)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TARGET)
	./$(TARGET)

clean:
	$(RM) $(OBJ) $(TARGET)
