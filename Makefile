.PHONY: all clean

# dll  -> so
# exe  -> --, elf, out
# lib  -> a
# obj  -> o

DEBUG ?= 0

RM = -@rm

ifeq ($(DEBUG), 0)
FLAG = -s
else
FLAG = -g -O0
endif


%.elf: main.o cio.o
	gcc $(FLAG) -o $@ $^ -lm
ifneq ($(DEBUG), 0)
	readelf -d $@
endif

%.o: %.c cio.h
	gcc $(FLAG) -c -o $@ $<

all:test.elf

clean:
	$(RM) *.o
	$(RM) *.elf
