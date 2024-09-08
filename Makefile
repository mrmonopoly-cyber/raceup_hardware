CC = gcc
C_FLAGS = -Wall -Wextra
C_EXFLAGS = 

raceup_hardware := $(or $(RACEUP_HW_ROOT), .)
raceup_hw.c := $(raceup_hardware)/raceup_hw.c

all: release

DEBUG_FLAGS = -O0 -fsanitize=address -g
RELEASE_FLAGS = -O2

debug: C_FLAGS += $(DEBUG_FLAGS)
debug: clean compile

release: C_FLAGS += $(RELEASE_FLAGS)
release: clean compile

compile: raceup_hw

raceup_hw: $(raceup_hw.c)
	$(CC) $(C_FLAGS) $(C_EXFLAGS) $(raceup_hw.c) -c

clean: 
	rm -f ./*.o
