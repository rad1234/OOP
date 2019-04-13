#define _CRT_SECURE_NO_WARNINGS
#include "service.h"
#include <string.h>
#include "validators.h"
#include <stdlib.h>

int serviceAdd(hangar *Hangar, char serialNumber[], char state[], char specialization[], char energyCapacity[])
{
	if (validateBot(Hangar, serialNumber) == 1)
		return 1;

	repoAdd(Hangar, serialNumber, state, specialization, atoi(energyCapacity));
	return 0;
}

int serviceUpdate(hangar * Hangar, char serialNumber[], char newState[], char newSpecialization[], char newEnergyCapacity[])
{
	if (validateBot(Hangar, serialNumber) == 0)
		return 1;

	repoUpdate(Hangar, serialNumber, newState, newSpecialization, atoi(newEnergyCapacity));
	return 0;
}

int serviceDelete(hangar * Hangar, char serialNumber[])
{
	if (validateBot(Hangar, serialNumber) == 0)
		return 1;

	repoDelete(Hangar, serialNumber);
	return 0;
}

const char * serviceListAll(hangar * Hangar)
{
	char botString[200] = "";
	botString[0] = 0;
	for (int index = 0; index < Hangar->arrayLength; index++)
	{
		char energyToString[20];
		strcat(botString, Hangar->bots[index].serialNumber);
		strcat(botString, " ");
		strcat(botString, Hangar->bots[index].state);
		strcat(botString, " ");
		strcat(botString, Hangar->bots[index].specialization);
		strcat(botString, " ");
		_itoa(Hangar->bots[index].energyCapacity, energyToString, 10);
		strcat(botString, energyToString);
		strcat(botString, "\n");
	}
	return botString;
}

const char * serviceListSpecial(hangar * Hangar, char specialization[])
{
	char botString[200] = "" ;
	botString[0] = 0;
	for (int index = 0; index < Hangar->arrayLength; index++)
	{
		if(strcmp(Hangar->bots[index].specialization, specialization) == 0)
		{
			char energyToString[20];
			strcat(botString, Hangar->bots[index].serialNumber);
			strcat(botString, " ");
			strcat(botString, Hangar->bots[index].state);
			strcat(botString, " ");
			strcat(botString, Hangar->bots[index].specialization);
			strcat(botString, " ");
			_itoa(Hangar->bots[index].energyCapacity, energyToString, 10);
			strcat(botString, energyToString);
			strcat(botString, "\n");
		}
	}
	return botString;
}
