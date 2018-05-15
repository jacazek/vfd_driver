PROJECT = main

# Root of source directory
LIBC = libc/
# Root of output directory
BIN = bin/
BIN_LIB = bin/lib/

TEST_BIN = test_bin/
# Root include directory
INCLUDE = include/
TEST_INCLUDE = Unity/

# From all non test source files create list of object files in output directory
LIB_OBJECTS = $(patsubst $(LIBC)%.c,$(BIN)%.o,$(filter-out $(wildcard $(LIBC)*_test.c), $(wildcard $(LIBC)*.c)))

# From all test source files create list of object files in test output directory
TEST_OBJECTS = $(patsubst $(LIBC)%.c,$(TEST_BIN)%.o, $(wildcard $(LIBC)*_test.c))

# Compiler options
CC = gcc
GAR = ar
CPPFLAGS = 
CFLAGS = 
ARFLAGS = rsc
CINCLUDE = -I$(INCLUDE)

rebuild: clean all

all: $(LIB_OBJECTS) $(PROJECT).c
	$(CC) $^ -o $(BIN)$(PROJECT).bin $(CINCLUDE) 

# archive: $(LIB_OBJECTS)
# 	$(AR) $(ARFLAGS) -o $(BIN_LIB_AVR)lib$@ $(BUILD)*.o

# Object files depend on source and headers
# headers do not get compiled so we only pass the first prerequisite ($<)
# as a file to compile
$(LIB_OBJECTS): $(BIN)%.o: $(LIBC)%.c $(INCLUDE)%.h
	$(CC) -c $< -o $@ $(CINCLUDE)

test.unit: all $(TEST_OBJECTS)

# test binaries depend on the test source and the library binaries... may want to depend on archives later
# After compiling and linking, we go ahead and run the test.
$(TEST_OBJECTS): $(TEST_BIN)%_test.o: $(LIBC)%_test.c $(BIN)%.o
	$(CC) $^ $(TEST_INCLUDE)unity.c -o $@ $(CINCLUDE) -I$(TEST_INCLUDE) # compile the test
	$@ # run the test

clean:
	rm -rf bin/*
	rm -rf test_bin/*