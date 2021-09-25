#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"
#include "dio.h"

uint8_t KeyPad_getPressedKey();

#define N_col 4
#define N_row 4

#define KEYPAD_PORT A

#endif /* KEYPAD_H_ */
