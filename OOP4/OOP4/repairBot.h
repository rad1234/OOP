#pragma once
typedef struct
{
	int energyCapacity;
	char* serialNumber;
	char* state;
	char* specialization;
}repairBot;

repairBot createBot(char* serialNumber, char* state, char* specialization, int energyCapacity);

repairBot createCopyBot(repairBot bot);

void botToString(repairBot bot, char botString[]);

int getEnergyCapacity(repairBot bot);

void destroyBot(repairBot* bot);