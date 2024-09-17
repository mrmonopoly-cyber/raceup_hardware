#ifndef __RACEUP_HW_VIRTUAL__
#define __RACEUP_HW_VIRTUAL__

#include <stdio.h>
#include <stdint.h>

typedef void virtualBoard;

#define  PH_ROOT_DIR "pheripherals"

#define SEPARATOR  "_"

#define ANALOG_PINS  "ANALOG"
#define DIGITAL_PINS  "DIGITAL"
#define SERIAL_MODULES  "SERIAL"
#define CAN_MODULES  "CAN"

typedef struct {
    uint8_t analog_pins;
    uint8_t digital_pins;
    uint8_t serial_modules;
    uint8_t can_modules;
}boardSpecs;

virtualBoard* virtual_board_init(const char* board_hash, const boardSpecs* board_spec);
void virtual_board_free(virtualBoard* board);

#endif //!__RACEUP_HW_VIRTUAL__
