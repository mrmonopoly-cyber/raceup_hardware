#ifndef __RACEUP_HW_SERIAL__
#define __RACEUP_HW_SERIAL__

#include <stdint.h>

int8_t serial_init(uint32_t frequency);
int32_t serial_read();
int8_t serial_write(uint32_t data);

#endif //!__RACEUP_HW_SERIAL__
