CC = gcc
C_FLAGS = -Wall -Wextra
C_EXFLAGS = 

raceup_hardware_serial := $(or $(RACEUP_HW_SERIAL_ROOT), .)
serial.c := $(raceup_hardware_serial)/serial.c

all: release

DEBUG_FLAGS = -O0 -fsanitize=address -g
RELEASE_FLAGS = -O2

debug: C_FLAGS += $(DEBUG_FLAGS)
debug: clean compile

release: C_FLAGS += $(RELEASE_FLAGS)
release: clean compile

compile: serial

serial: $(serial.c)
	$(CC) $(C_FLAGS) $(C_EXFLAGS) $(serial.c) -c

clean_serial:
	rm -f ./*.o

clean: clean_serial
