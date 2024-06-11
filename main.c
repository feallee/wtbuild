#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <stdlib.h>
#include "LibVersion.h"
#include "LibTime.h"
#define CONTEXT \
"#ifndef __WT_BUILD_H_\n"\
"#define __WT_BUILD_H_\n"\
"#define WT_BUILD_YEAR_4 %d\n"\
"#define WT_BUILD_YEAR_3 %d\n"\
"#define WT_BUILD_YEAR_2 %d\n"\
"#define WT_BUILD_YEAR_1 %d\n"\
"#define WT_BUILD_MONTH_2 %d\n"\
"#define WT_BUILD_MONTH_1 %d\n"\
"#define WT_BUILD_DAY_2 %d\n"\
"#define WT_BUILD_DAY_1 %d\n"\
"#define WT_BUILD_HOUR_2 %d\n"\
"#define WT_BUILD_HOUR_1 %d\n"\
"#define WT_BUILD_MINUTE_2 %d\n"\
"#define WT_BUILD_MINUTE_1 %d\n"\
"#define WT_BUILD_SECOND_2 %d\n"\
"#define WT_BUILD_SECOND_1 %d\n"\
"\n#define WT_BUILD_VERSION_MAJOR %hu\n"\
"#define WT_BUILD_VERSION_MINOR %hu\n"\
"#define WT_BUILD_VERSION_PATCH %hu\n" \
"#endif\n"



int main(int argc, char* argv[])
{
	struct tm info;
	LibTime_Now(&info);
	if (argc == 2)
	{
		FILE* fp = fopen(argv[1], "w+");

		fprintf(fp, CONTEXT,
			LibTime_GetDigit(info.tm_year, 4),
			LibTime_GetDigit(info.tm_year, 3),
			LibTime_GetDigit(info.tm_year, 2),
			LibTime_GetDigit(info.tm_year, 1),
			LibTime_GetDigit(info.tm_mon, 2),
			LibTime_GetDigit(info.tm_mon, 1),
			LibTime_GetDigit(info.tm_mday, 2),
			LibTime_GetDigit(info.tm_mday, 1),
			LibTime_GetDigit(info.tm_hour, 2),
			LibTime_GetDigit(info.tm_hour, 1),
			LibTime_GetDigit(info.tm_min, 2),
			LibTime_GetDigit(info.tm_min, 1),
			LibTime_GetDigit(info.tm_sec, 2),
			LibTime_GetDigit(info.tm_sec, 1),
			1, 0, 0);
		fclose(fp);
		printf("%d%d%d%d/%d%d/%d%d %d%d:%d%d:%d%d\n",
			LibTime_GetDigit(info.tm_year, 4),
			LibTime_GetDigit(info.tm_year, 3),
			LibTime_GetDigit(info.tm_year, 2),
			LibTime_GetDigit(info.tm_year, 1),
			LibTime_GetDigit(info.tm_mon, 2),
			LibTime_GetDigit(info.tm_mon, 1),
			LibTime_GetDigit(info.tm_mday, 2),
			LibTime_GetDigit(info.tm_mday, 1),
			LibTime_GetDigit(info.tm_hour, 2),
			LibTime_GetDigit(info.tm_hour, 1),
			LibTime_GetDigit(info.tm_min, 2),
			LibTime_GetDigit(info.tm_min, 1),
			LibTime_GetDigit(info.tm_sec, 2),
			LibTime_GetDigit(info.tm_sec, 1));
	}
	else if (argc > 2)
	{
		FILE* fp = fopen(argv[1], "w+");
		uint16_t ma = 1, mi = 0, pa = 0, id = atoi(argv[2]);
		LibVersion_Get(id, &ma, &mi, &pa);
		pa++;
		if (pa > 999)
		{
			pa = 0;
			mi++;
		}
		if (mi > 999)
		{
			mi = 0;
			ma++;
		}
		if (ma > 999)
		{
			ma = 0;
		}

		fprintf(fp, CONTEXT,
			LibTime_GetDigit(info.tm_year, 4),
			LibTime_GetDigit(info.tm_year, 3),
			LibTime_GetDigit(info.tm_year, 2),
			LibTime_GetDigit(info.tm_year, 1),
			LibTime_GetDigit(info.tm_mon, 2),
			LibTime_GetDigit(info.tm_mon, 1),
			LibTime_GetDigit(info.tm_mday, 2),
			LibTime_GetDigit(info.tm_mday, 1),
			LibTime_GetDigit(info.tm_hour, 2),
			LibTime_GetDigit(info.tm_hour, 1),
			LibTime_GetDigit(info.tm_min, 2),
			LibTime_GetDigit(info.tm_min, 1),
			LibTime_GetDigit(info.tm_sec, 2),
			LibTime_GetDigit(info.tm_sec, 1),
			ma, mi, pa);
		fclose(fp);
		printf("%d%d%d%d/%d%d/%d%d %d%d:%d%d:%d%d %hu.%hu.%hu\n",
			LibTime_GetDigit(info.tm_year, 4),
			LibTime_GetDigit(info.tm_year, 3),
			LibTime_GetDigit(info.tm_year, 2),
			LibTime_GetDigit(info.tm_year, 1),
			LibTime_GetDigit(info.tm_mon, 2),
			LibTime_GetDigit(info.tm_mon, 1),
			LibTime_GetDigit(info.tm_mday, 2),
			LibTime_GetDigit(info.tm_mday, 1),
			LibTime_GetDigit(info.tm_hour, 2),
			LibTime_GetDigit(info.tm_hour, 1),
			LibTime_GetDigit(info.tm_min, 2),
			LibTime_GetDigit(info.tm_min, 1),
			LibTime_GetDigit(info.tm_sec, 2),
			LibTime_GetDigit(info.tm_sec, 1),
			ma, mi, pa);
	}
	else
	{
		printf("ERROR\n");
	}

	return 0;
}

