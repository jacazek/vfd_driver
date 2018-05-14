PROJECT = main

# Root of source directory
LIBC = libc/
# Root of output directory
BIN = bin/
# Root include directory
INCLUDE = include/

# From all source files not in test directory create list of object files in output directory
LIB_OBJECTS = $(patsubst $(LIBC)%.c,$(BIN)%.o,$(filter-out $(wildcard $(LIBC)*_test.c), $(wildcard $(LIBC)*.c)))

# Compiler options
CC = gcc
CPPFLAGS = 
CFLAGS = 
CINCLUDE = -I$(INCLUDE)

rebuild: clean all

all: $(LIB_OBJECTS) $(PROJECT).c
	$(CC) $^ -o $(BIN)$(PROJECT).bin $(CINCLUDE) 

$(LIB_OBJECTS): $(BIN)%.o: $(LIBC)%.c
	$(CC) -c $^ -o $@ $(CINCLUDE)

clean:
	rm -rf bin/*