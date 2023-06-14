CC=cc
OUTPUT=mkfs.nsfs.exe
CC_FLAGS=-std=c17 -Iinclude -Ilibdisk/include
CC_SRC=$(wildcard *.c) $(wildcard libdisk/*.c)

.PHONY: all
all:
	$(CC) -o $(OUTPUT) $(CC_FLAGS) $(CC_SRC)

.PHONY: distclean
distclean:
	rm -f $(OUTPUT)
