#pragma once
#include "repairBot.h"

typedef struct
{
	repairBot *bots;
	int arrayLength;
	int arrayCapacity;
}hangar;


void repoInit(hangar *Hangar);

repairBot repoAdd(hangar *Hangar, repairBot bot);

repairBot  repoUpdate(hangar *Hangar,repairBot bot);

repairBot repoDelete(hangar *Hangar,repairBot bot);

hangar* filterHangar(hangar *Hangar, int(*funcToCompare)(repairBot bot, char stringToCompare[]), char string[]);

void orderRepoBy(hangar *Hangar, int(*funcToOrder)(repairBot bot0, repairBot bot1));

void destroyHangar(hangar *Hangar);

typedef struct
{
	repairBot(*operationPointer)(hangar*, repairBot);
	repairBot repairBot;
}operation;

typedef struct
{
	operation* operations;
	int size;
	int capacity;
}operationArray;

void operationArrayInit(operationArray* operation);

operation  operationInit(void(*operationPointer)(hangar*, repairBot), repairBot bot);

operation inverseOperationInit(void(*operationPointer)(hangar*, repairBot), repairBot bot);

void removeOperation(operationArray* operations);

void addOperation(operationArray* operationsToUndo, operation operation);

void destroyOperationArray(operationArray* operations);

void repoToString(hangar* Hangar,char botString[]);