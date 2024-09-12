ifndef CC
CC = gcc
C_FLAGS = -Wall -Wextra
C_EXFLAGS = 
endif

raceup_hardware := $(or $(RACEUP_HW_ROOT), .)
raceup_hw.c := $(raceup_hardware)/raceup_hw.c

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

