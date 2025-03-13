# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall -Wextra -std=c11
# Output binary name
TARGET = todo

# Default rule
all: $(TARGET)

# Link and compile
$(TARGET): main.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c

# Clean up build files
clean:
	rm -f $(TARGET)