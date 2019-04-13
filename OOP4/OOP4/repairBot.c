#define _CRT_SECURE_NO_WARNINGS
#include "repairBot.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


repairBot createBot(char* serialNumber, char* state, char* specialization, int energyCapacity)
{
	repairBot Bot;

	Bot.serialNumber =  (char*)malloc(20 * sizeof(char));
	Bot.specialization = (char*)malloc(20 * sizeof(char));
	Bot.state = (char*)malloc(20 * sizeof(char));

	strcpy(Bot.serialNumber, serialNumber);
	strcpy(Bot.specialization, specialization);
	strcpy(Bot.state, state);
	
	Bot.energyCapacity = energyCapacity;

	return Bot;
}

repairBot createCopyBot(repairBot bot)
{
	repairBot copyBot;

	copyBot.serialNumber = (char*)malloc(20 * sizeof(char));
	copyBot.specialization = (char*)malloc(20 * sizeof(char));
	copyBot.state = (char*)malloc(20 * sizeof(char));

	strcpy(copyBot.serialNumber, bot.serialNumber);
	strcpy(copyBot.state, bot.state);
	strcpy(copyBot.specialization, bot.specialization);
	copyBot.energyCapacity = bot.energyCapacity;

	return copyBot;
}

int getEnergyCapacity(repairBot bot)
{
	return bot.energyCapacity;
}

void destroyBot(repairBot* bot)
{
	free(bot->serialNumber);
	free(bot->specialization);
	free(bot->state);
}


void botToString(repairBot bot, char botString[])
{
	char energytoString[20];
	strcat(botString, bot.serialNumber);
	strcat(botString, " ");
	strcat(botString, bot.state);
	strcat(botString, " ");
	strcat(botString, bot.specialization);
	strcat(botString, " ");
	_itoa(bot.energyCapacity, energytoString, 10);
	strcat(botString, energytoString);
}


