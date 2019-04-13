#pragma once
typedef struct 
{
	int energyCapacity;
	char serialNumber[20], state[20], specialization[20];
}repairBot;

repairBot createBot(char serialNumber[], char state[], char specialization[], int energyCapacity);

