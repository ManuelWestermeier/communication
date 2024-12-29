#pragma once

#include "./user.hpp"

#define BAUD_RATE 200000
#define PIN_ROOT 25

#define SEND_PIN PIN_ROOT + IS_SENDING
#define RECEIVE_PIN PIN_ROOT + !IS_SENDING