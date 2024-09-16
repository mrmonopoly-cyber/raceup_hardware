#include "pins.h"
#include <stdlib.h>

int8_t set_pin_mode_analog(const uint32_t pin,
                           const enum RACEUP_HW_PIN_MODE mode)
{
    return EXIT_FAILURE;
}
int8_t set_pin_mode_digital(const uint32_t pin,
                            const enum RACEUP_HW_PIN_MODE mode)
{
    return EXIT_FAILURE;
}

uint32_t read_pin_analog(const uint32_t pin)
{
    return EXIT_FAILURE;
}
uint32_t read_pin_digital(const uint32_t pin)
{
    return EXIT_FAILURE;
}

int8_t write_pin_analog(const uint32_t pin, const uint32_t data)
{
    return EXIT_FAILURE;
}
int8_t write_pin_digital(const uint32_t pin, const uint32_t data)
{
    return EXIT_FAILURE;
}
