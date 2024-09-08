CC = gcc
C_FLAGS = -Wall -Wextra
C_EXFLAGS = 

raceup_hardware_pins := $(or $(RACEUP_HW_PINS_ROOT), .)
pins.c := $(raceup_hardware_pins)/pins.c

all: release

DEBUG_FLAGS = -O0 -fsanitize=address -g
RELEASE_FLAGS = -O2

debug: C_FLAGS += $(DEBUG_FLAGS)
debug: clean compile

release: C_FLAGS += $(RELEASE_FLAGS)
release: clean compile

compile: pins

pins: $(pins.c)
	$(CC) $(C_FLAGS) $(C_EXFLAGS) $(pins.c) -c

clean_pins:
	rm -f ./*.o

clean: clean_pins
