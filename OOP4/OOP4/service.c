#define _CRT_SECURE_NO_WARNINGS
#include "service.h"
#include "validator.h"
#include <stdlib.h>
#include <string.h>

int serviceAdd(operationArray* undo, operationArray* redo, hangar *Hangar, char* serialNumber, char* state, char* specialization, char* energyCapacity)
{
	if (validateBot(Hangar, serialNumber) == 1)
		return 1;

	repairBot newBot = createBot(serialNumber, state, specialization, atoi(energyCapacity));
	repairBot operationBot;
	operation operationToUndo;

	operationBot = repoAdd(Hangar, newBot);

	operationToUndo = operationInit(repoDelete, operationBot);

	addOperation(undo, operationToUndo);
	
	return 0;
}

int serviceUpdate(operationArray* undo, operationArray* redo, hangar * Hangar, char* serialNumber, char* newState, char* newSpecialization, char* newEnergyCapacity)
{
	if (validateBot(Hangar, serialNumber) == 0)
		return 1;

	repairBot newBot = createBot(serialNumber, newState, newSpecialization, atoi(newEnergyCapacity));
	repairBot operationBot;
	operation operationToUndo;

	operationBot = repoUpdate(Hangar, newBot);

	operationToUndo = operationInit(repoUpdate, operationBot);

	addOperation(undo, operationToUndo);
		
	return 0;
}

int serviceDelete(operationArray* undo, operationArray* redo, hangar *Hangar, char* serialNumber)
{
	if (validateBot(Hangar, serialNumber) == 0)
		return 1;

	repairBot newBot = createBot(serialNumber, "", "", 0);
	repairBot operationBot;
	operation operationToUndo;

	operationBot = repoDelete(Hangar, newBot);

	operationToUndo = operationInit(repoAdd, operationBot);

	addOperation(undo, operationToUndo);

	destroyBot(&newBot);
	return 0;
}



void serviceListAll(hangar *Hangar, char botString[])
{
	
	repoToString(Hangar, botString);
}

int alpthabeticByState(repairBot bot0, repairBot bot1)
{
	if (strcmp(bot0.state, bot1.state) > 0)
		return 1;

	return 0;
}
int compareSpecialization(repairBot bot, char specialization[]) {
	if (strcmp(bot.specialization, specialization) == 0) return 1;
	return 0;
}

int compareEnergyCapacity(repairBot bot, char energyCapacity[]) {
	if (bot.energyCapacity < atoi(energyCapacity)) return 1;
	return 0;
}

void printByEnergy(hangar *Hangar, char botString[], char* energy)
{
	
	botString[0] = 0;
	hangar* filteredHangar = filterHangar(Hangar, compareEnergyCapacity, energy);
	orderRepoBy(filteredHangar, alpthabeticByState);
	repoToString(filteredHangar, botString);
	destroyHangar(filteredHangar);
}

void printBySpecialization(hangar *Hangar, char botString[], char* specialization)
{
	botString[0] = 0;
	hangar* filteredHangar = filterHangar(Hangar, compareSpecialization, specialization);
	repoToString(filteredHangar, botString);
	destroyHangar(filteredHangar);
}

int serviceUndo(operationArray* undo, operationArray* redo, hangar* Hangar)
{
	if (undo->size > 0)
	{

		repairBot redoBot = undo->operations[undo->size - 1].operationPointer(Hangar, createCopyBot(undo->operations[undo->size - 1].repairBot));

		operation redoOperation = inverseOperationInit(undo->operations[undo->size - 1].operationPointer, redoBot);

		addOperation(redo, redoOperation);
		removeOperation(undo);

		return 0;
	}

	return 1;
}

int serviceRedo(operationArray* undo, operationArray* redo, hangar* Hangar)
{
	if (redo->size > 0)
	{
		repairBot undoBot = redo->operations[redo->size - 1].operationPointer(Hangar, createCopyBot(redo->operations[redo->size - 1].repairBot));
		
		operation undoOperation = inverseOperationInit(redo->operations[redo->size - 1].operationPointer, undoBot);
		addOperation(undo, undoOperation);
		removeOperation(redo);
		return 0;
	}
	return 1;
}



