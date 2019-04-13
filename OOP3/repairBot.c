#define _CRT_SECURE_NO_WARNINGS
#include "repairBot.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


repairBot createBot(char serialNumber[], char state[], char specialization[], int energyCapacity)
{
	repairBot Bot;
	strcpy(Bot.serialNumber, serialNumber);
	strcpy(Bot.state, state);
	strcpy(Bot.specialization, specialization);
	Bot.energyCapacity = energyCapacity;
	return Bot;
}



