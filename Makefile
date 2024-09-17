ifndef CC
CC = gcc
C_FLAGS = -Wall -Wextra
C_EXFLAGS = 
endif

DEBUG_FLAGS = -O0 -fsanitize=address -g
RELEASE_FLAGS = -O2

raceup_hardware := $(or $(RACEUP_HW_ROOT), .)
raceup_hw.cpp := $(raceup_hardware)/raceup_hw.cpp

ifndef $(RACEUP_HW_CAN_ROOT)
	RACEUP_HW_CAN_ROOT := $(raceup_hardware)/src/can
	include $(RACEUP_HW_CAN_ROOT)/Makefile
endif

ifndef $(RACEUP_HW_SERIAL_ROOT)
	RACEUP_HW_SERIAL_ROOT := $(raceup_hardware)/src/serial
	include $(RACEUP_HW_SERIAL_ROOT)/Makefile
endif

ifndef $(RACEUP_HW_PINS_ROOT)
	RACEUP_HW_PINS_ROOT := $(raceup_hardware)/src/pins
	include $(RACEUP_HW_PINS_ROOT)/Makefile
endif

ifndef $(RACEUP_HW_VIRTUAL_ROOT)
	RACEUP_HW_VIRTUAL_ROOT := $(raceup_hardware)/src/virtual
	include $(RACEUP_HW_VIRTUAL_ROOT)/Makefile
endif

all: release

debug: C_FLAGS += $(DEBUG_FLAGS)
debug: clean compile

release: C_FLAGS += $(RELEASE_FLAGS)
release: clean compile

compile: raceup_hw

raceup_hw: $(raceup_hw.cpp)
	$(CC) $(C_FLAGS) $(C_EXFLAGS) $(raceup_hw.cpp) -c

raceup_hw_clean: 
	rm -f ./*.o

clean: raceup_hw_clean
