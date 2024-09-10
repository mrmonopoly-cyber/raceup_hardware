CC = gcc
C_FLAGS = -Wall -Wextra
C_EXFLAGS = 

raceup_hardware_dummy := $(or $(RACEUP_HW_DUMMY_ROOT), .)
dummy.c := $(raceup_hardware_dummy)/dummy.c

all: release

DEBUG_FLAGS = -O0 -fsanitize=address -g
RELEASE_FLAGS = -O2

debug: C_FLAGS += $(DEBUG_FLAGS)
debug: clean compile

release: C_FLAGS += $(RELEASE_FLAGS)
release: clean compile

compile: dummy

dummy: $(dummy.c)
	$(CC) $(C_FLAGS) $(C_EXFLAGS) $(dummy.c) -c

clean_dummy:
	rm -f ./*.o

clean: clean_dummy
