#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include "Repo.h"
#include <string.h>
hangar repoInit()
{
	hangar Hangar;
	Hangar.arrayCapacity = 30;
	Hangar.arrayLength = 0;
	repairBot bots[30];
	return Hangar;
}

void repoAdd(hangar * Hangar, char serialNumber[], char state[], char specialization[], int energyCapacity)
{
	repairBot newBot = createBot(serialNumber, state, specialization, energyCapacity);
	Hangar->bots[Hangar->arrayLength] = newBot;
	Hangar->arrayLength++;
}

void repoUpdate(hangar * Hangar, char serialNumber[], char newState[], char newSpecialization[], int newEnergyCapacity)
{
	
	for (int index = 0; index < Hangar->arrayLength; index++)
		if (strcmp(Hangar->bots[index].serialNumber, serialNumber) == 0)
		{
			strcpy(Hangar->bots[index].state, newState);
			strcpy(Hangar->bots[index].specialization, newSpecialization);
			Hangar->bots[index].energyCapacity = newEnergyCapacity;
			
		}
}

void repoDelete(hangar * Hangar, char serialNumber[])
{
	int index = 0, exists = 0;

	while (index < Hangar->arrayLength && exists == 0)
	{
		if (strcmp(Hangar->bots[index].serialNumber,serialNumber) != 0)
			index++;
		else
			exists = 1;
	}

	while (index < Hangar->arrayLength - 1)
	{
		Hangar->bots[index] = Hangar->bots[index + 1];
		index++;
	}

	Hangar->arrayLength--;
}

