CC = gcc
CFLAGS = -Wall -Iinclude
SRC = src/loading_screen.c
OBJ = $(SRC:.c=.o)
EXAMPLE_SRC = examples/demo.c
TARGET = loading_screen_demo.exe

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ) $(EXAMPLE_SRC)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
