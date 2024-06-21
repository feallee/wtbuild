#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "LibVersion.h"

#define FILE_PATH "LibVersion.dat"
typedef struct
{
	uint16_t Id;
	uint16_t Major;
	uint16_t Minor;
	uint16_t Patch;
} LibVersion_RecordType;

static FILE* New(void)
{
	return fopen(FILE_PATH, "wb");
}

static FILE* Open(void)
{
	FILE* fp = fopen(FILE_PATH, "rb+");
	if (!fp)
	{
		fp = New();
	}
	return fp;
}

static void Close(FILE* fp)
{
	if (fp)
	{
		fclose(fp);
	}
}

bool LibVersion_Get(uint16_t* major, uint16_t* minor, uint16_t* patch)
{
	bool r = false;
	FILE* fp = Open();
	if (fp)
	{
		LibVersion_RecordType record;

		if (fread(&record, sizeof(LibVersion_RecordType), 1, fp) == 1)
		{
			if (++record.Patch > 999)
			{
				record.Patch = 0;
				if (++record.Minor > 999)
				{
					record.Minor = 0;
					if (++record.Major > 999)
					{
						record.Major = 1;
					}
				}
			}

			*major = record.Major;
			*minor = record.Minor;
			*patch = record.Patch;
			fseek(fp, sizeof(LibVersion_RecordType) * -1, SEEK_CUR);
			fwrite(&record, sizeof(LibVersion_RecordType), 1, fp);
		}
		else
		{
			record.Id = 0;
			*major = record.Major = 1;
			*minor = record.Minor = 0;
			*patch = record.Patch = 0;
			fseek(fp, 0, SEEK_END);
			fwrite(&record, sizeof(LibVersion_RecordType), 1, fp);
		}
		Close(fp);
		r = true;
	}
	return r;
}

