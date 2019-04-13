#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include"Repo.h"
#include <string.h>

void repoInit(hangar* Hangar)
{  

	Hangar->arrayCapacity = 1;
	Hangar->arrayLength = 0;
	Hangar->bots = (repairBot*)malloc(Hangar->arrayCapacity * sizeof(repairBot));
}

void resize(hangar *Hangar)
{
	Hangar->arrayCapacity *= 2;
	Hangar->bots = (repairBot*)realloc(Hangar->bots, Hangar->arrayCapacity * sizeof(repairBot));
}

repairBot repoAdd(hangar * Hangar, repairBot bot)
{
	repairBot newBot = createCopyBot(bot);
	Hangar->bots[Hangar->arrayLength] = newBot;
	Hangar->arrayLength++;

	if (Hangar->arrayLength == Hangar->arrayCapacity)
		resize(Hangar);

	return newBot;
}

repairBot repoUpdate(hangar *Hangar,repairBot bot)
{
	repairBot newBot;
	for (int index = 0; index < Hangar->arrayLength; index++)
		if (strcmp(bot.serialNumber, Hangar->bots[index].serialNumber) == 0)
		{
			newBot = createCopyBot(Hangar->bots[index]);
			destroyBot(&Hangar->bots[index]);
			Hangar->bots[index] = bot;
			return newBot;
		}
}

repairBot repoDelete(hangar *Hangar, repairBot bot)
{
	int index = 0, exists = 0;
	repairBot newBot;

	while (index < Hangar->arrayLength && exists == 0)
	{
		if (strcmp(bot.serialNumber, Hangar->bots[index].serialNumber) != 0)
			index++;
		else
			exists = 1;
	}

	newBot = createCopyBot(Hangar->bots[index]);

	//destroyBot(&Hangar->bots[index]);
	//destroyBot(&bot);

	while (index < Hangar->arrayLength-1)
	{
		
		Hangar->bots[index] = Hangar->bots[index + 1];
		index++;
	}

	Hangar->arrayLength--;

	return newBot;
}

hangar* filterHangar(hangar *Hangar, int(*funcToCompare)(repairBot bot, char stringToCompare[]), char string[])
{
	hangar* filteredHangar = (hangar*)malloc(sizeof(hangar));
	repoInit(filteredHangar);
	for (int index = 0; index < Hangar->arrayLength; index++)
		if (funcToCompare(Hangar->bots[index], string))
		{
			repoAdd(filteredHangar, createBot(
				Hangar->bots[index].serialNumber,
				Hangar->bots[index].state,
				Hangar->bots[index].specialization,
				Hangar->bots[index].energyCapacity
			));
		}
	return filteredHangar;
}

void orderRepoBy(hangar *Hangar, int(*funcToOrder)(repairBot bot0, repairBot bot1))
{
	for (int index = 0; index < Hangar->arrayLength - 1; index++)
		for (int j = index + 1; j < Hangar->arrayLength; j++)
			if (funcToOrder(Hangar->bots[index], Hangar->bots[j]))
			{
				repairBot tempoBot = Hangar->bots[index];
				Hangar->bots[index] = Hangar->bots[j];
				Hangar->bots[j] = tempoBot;
			}
}

void destroyHangar(hangar* Hangar)
{
	for (int index = 0; index < Hangar->arrayLength; index++)
		destroyBot(&Hangar->bots[index]);

	free(Hangar->bots);
	free(Hangar);
}

void repoToString(hangar *Hangar, char botString[])
{
	for (int index = 0; index < Hangar->arrayLength; index++)
	{
		botToString(Hangar->bots[index], botString);
		strcat(botString, "\n");
	}
}

