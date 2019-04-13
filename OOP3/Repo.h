#pragma once
#include "repairBot.h"

typedef struct
{
	repairBot bots[30];
	int arrayLength;
	int arrayCapacity;
}hangar;

hangar repoInit();

void repoAdd(hangar *Hangar, char serialNumber[], char state[], char specialization[], int energyCapacity);

void  repoUpdate(hangar *Hangar, char serialNumber[], char newState[], char newSpecialization[], int newEnergyCapacity);

void repoDelete(hangar *Hangar, char serialNumber[]);