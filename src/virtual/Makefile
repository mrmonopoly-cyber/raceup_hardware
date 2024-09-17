ifndef CC
CC = gcc
C_FLAGS = -Wall -Wextra
C_EXFLAGS = 
endif

raceup_hardware_virtual := $(or $(RACEUP_HW_VIRTUAL_ROOT), .)
virtual.c := $(raceup_hardware_virtual)/virtual.c

all: release

DEBUG_FLAGS = -O0 -fsanitize=address -g
RELEASE_FLAGS = -O2

debug: C_FLAGS += $(DEBUG_FLAGS)
debug: clean compile

release: C_FLAGS += $(RELEASE_FLAGS)
release: clean compile

compile: virtual

virtual: $(virtual.c)
	$(CC) $(C_FLAGS) $(C_EXFLAGS) $(virtual.c) -c

clean_virtual:
	rm -f ./*.o

clean: clean_virtual
