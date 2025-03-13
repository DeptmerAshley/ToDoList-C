# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall -Wextra -std=c99
# Output binary name
TARGET = todo

# Source files
SRCS = main.c
# Object files (replace .c with .o)
OBJS = $(SRCS:.c=.o)

# Default rule
all: $(TARGET)

# Link and compile
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(TARGET) $(OBJS)
