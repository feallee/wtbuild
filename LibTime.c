#include "LibTime.h"
void LibTime_Now(struct tm* value)
{
	time_t rawtime;
	time(&rawtime);
	localtime_s(value, &rawtime);
	value->tm_year += 1900;
	value->tm_mon += 1;
}
uint8_t LibTime_GetDigit(int value, uint8_t position)
{
	int digit = 0;
	for (int i = 0; i < position; i++) {
		digit = value % 10;
		value /= 10;
	}
	return digit;
}
