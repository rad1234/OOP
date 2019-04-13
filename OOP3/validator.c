#include "validators.h"
#include <string.h>

int validateBot(hangar *Hangar, char serialNumber[])
{
	for (int index = 0; index < Hangar->arrayLength; index++)
	{
		if (strcmp(serialNumber, Hangar->bots[index].serialNumber) == 0)
			return 1;
	}
	return 0;
}