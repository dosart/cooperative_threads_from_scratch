SOURCES=$(shell find -name "*.c")

CC=gcc

CFLAGS=-I ./include -Werror -Wall -Wextra -Wpedantic -Wcast-align -Wcast-qual -Wconversion -Wenum-compare -Wfloat-equal -Wredundant-decls -Wsign-conversion

OUTPUT_DIR =./bin

.PHONY: mkdir_build clean clean_all run format

all: mkdir_build build

build:
	$(CC) $(CFLAGS) $(SOURCES) -o threads

mkdir_build:
	$(shell [ ! -d  $(OUTPUT_DIR) ] && mkdir $(OUTPUT_DIR))

clean:
	rm $(shell find . -name "*.o")

clean_all: 
	@make clean
	rm $(OUTPUT_DIR)/kernel

run:
	$(OUTPUT_DIR)/threads

format:
	find . -regex '.*\.\(c\|h\)' -exec clang-format -style=file -i {} \;