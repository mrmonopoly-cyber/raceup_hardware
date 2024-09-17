ifndef CC
CC = gcc
C_FLAGS = -Wall -Wextra
C_EXFLAGS = 
endif

RACEUP_HW_VIRTUAL_ROOT=./..
include $(RACEUP_HW_VIRTUAL_ROOT)/Makefile

main.c := ./main.c
all: release

DEBUG_FLAGS = -O0 -fsanitize=address -g
RELEASE_FLAGS = -O2

debug: C_FLAGS += $(DEBUG_FLAGS)
debug: clean compile

release: C_FLAGS += $(RELEASE_FLAGS)
release: clean compile

compile: main 

main: $(main.c)
	$(CC) $(C_FLAGS) $(C_EXFLAGS) $(main.c) $(wildcard *.o) -lssl -lcrypto -o main

clean_virtual_test:
	rm -rf ./pheripherals
	rm -f ./main

clean: clean_virtual_test
