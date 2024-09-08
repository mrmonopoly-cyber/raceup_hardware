#ifndef __RACEUP_HW_PINS__
#define __RACEUP_HW_PINS__

#include <stdint.h>

enum RACEUP_HW_PIN_MODE { HIGH, LOW };

int8_t set_pin_mode_analog(const uint32_t pin,
                           const enum RACEUP_HW_PIN_MODE mode);
int8_t set_pin_mode_digital(const uint32_t pin,
                            const enum RACEUP_HW_PIN_MODE mode);

uint32_t read_pin_analog(const uint32_t pin);
uint32_t read_pin_digital(const uint32_t pin);

int8_t write_pin_analog(const uint32_t pin, const uint32_t data);
int8_t write_pin_digital(const uint32_t pin, const uint32_t data);

#endif //!__RACEUP_HW_PINS__
