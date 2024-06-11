#ifndef __LIB_TIME_H_
#define __LIB_TIME_H_
#include <stdint.h>
#include <time.h>
void LibTime_Now(struct tm* value);
uint8_t LibTime_GetDigit(int value, uint8_t position);

#endif // ! __LIB_TIME_H_
