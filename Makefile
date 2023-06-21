SOURCES=$(shell find -name "*.c")
BUILDS=$(shell find -name "*.o")

CC=gcc

CFLAGS=-I ./include -Werror -Wall -Wextra -Wpedantic -Wcast-align -Wcast-qual -Wconversion -Wenum-compare -Wfloat-equal -Wredundant-decls -Wsign-conversion

OUTPUT_DIR =./bin

.PHONY: mkdir_build clean clean_all run format

all: mkdir_build build

build:
	$(CC) $(CFLAGS) $(SOURCES) -o $(OUTPUT_DIR)/threads

mkdir_build:
	$(shell [ ! -d  $(OUTPUT_DIR) ] && mkdir $(OUTPUT_DIR))

clean:
	find . -name "*.o" -type f -delete

clean_all: 
	@make clean
	rm -r $(OUTPUT_DIR)

run:
	$(OUTPUT_DIR)/threads

format:
	find . -regex '.*\.\(c\|h\)' -exec clang-format -style=file -i {} \;