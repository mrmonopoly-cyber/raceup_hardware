#include "pins.h"

#include <stdio.h>
#include <stdlib.h>

static char* RATEC_ENV = NULL;

#define CHECK_RATEC_ENV() \
    if (!RATEC_ENV) { \
        RATEC_ENV = getenv("RATEC_ENV"); \
        if (!RATEC_ENV) {\
            perror("ratec environment not found");\
        }\
    }


typedef struct {
    char* pin_path_file;
    uint8_t read : 1;
    uint8_t write: 1;
}pin_cfg;



int8_t set_pin_mode_analog(const uint32_t pin,
                           const enum RACEUP_HW_PIN_MODE mode)
{
    CHECK_RATEC_ENV();

    return EXIT_FAILURE;
}
int8_t set_pin_mode_digital(const uint32_t pin,
                            const enum RACEUP_HW_PIN_MODE mode)
{
    CHECK_RATEC_ENV();

    return EXIT_FAILURE;
}

uint32_t read_pin_analog(const uint32_t pin)
{
    CHECK_RATEC_ENV();

    return EXIT_FAILURE;
}
uint32_t read_pin_digital(const uint32_t pin)
{
    CHECK_RATEC_ENV();

    return EXIT_FAILURE;
}

int8_t write_pin_analog(const uint32_t pin, const uint32_t data)
{
    CHECK_RATEC_ENV();

    return EXIT_FAILURE;
}
int8_t write_pin_digital(const uint32_t pin, const uint32_t data)
{
    CHECK_RATEC_ENV();

    return EXIT_FAILURE;
}
