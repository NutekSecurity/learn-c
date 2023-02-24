CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -I../unity

SRC = grasshoper-gradebook.c
UNITY_SRC = ../unity/unity.c

TARGET = grasshoper-gradebook

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC) $(UNITY_SRC)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)
	rm -f *.o

