CC = gcc
CFLAGS = -Wall -Iinclude
SRC = src/loading_screen.c
OBJ = $(SRC:.c=.o)
EXAMPLE_SRC = examples/demo.c

ifeq ($(OS),Windows_NT)
    TARGET = loading_screen_demo.exe
    RM = del
else
    TARGET = loading_screen_demo
    RM = rm -f
endif

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ) $(EXAMPLE_SRC)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(TARGET)
