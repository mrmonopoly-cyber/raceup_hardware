CC = gcc
C_FLAGS = -Wall -Wextra
C_EXFLAGS = 

raceup_hardware_can := $(or $(RACEUP_HW_CAN_ROOT), .)
can.c := $(raceup_hardware_can)/can.c

all: release

DEBUG_FLAGS = -O0 -fsanitize=address -g
RELEASE_FLAGS = -O2

debug: C_FLAGS += $(DEBUG_FLAGS)
debug: clean compile

release: C_FLAGS += $(RELEASE_FLAGS)
release: clean compile

compile: can

can: $(can.c)
	$(CC) $(C_FLAGS) $(C_EXFLAGS) $(can.c) -c

clean_can: 
	rm -f ./*.o

clean: clean_can
