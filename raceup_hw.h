#ifndef __RACEUP_HW__
#define __RACEUP_HW__

#ifdef __RACEUP_LINUX__
#include <string>
int init_board(const std::string &);
#endif

#include "src/can/can.h"
#include "src/pins/pins.h"
#include "src/serial/serial.h"

#endif
