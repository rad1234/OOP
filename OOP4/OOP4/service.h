#pragma once
#include <stdio.h>
#include "Repo.h"


int serviceAdd(operationArray* undo, operationArray* redo, hangar *Hangar, char serialNumber[], char state[], char specialization[], char energyCapacity[]);

int serviceUpdate(operationArray* undo, operationArray* redo, hangar *Hangar, char serialNumber[], char newState[], char newSpecialization[], char newEnergyCapacity[]);

int serviceDelete(operationArray* undo, operationArray* redo, hangar *Hangar, char serialNumber[]);

void serviceListAll(hangar *Hangar,char string[]);

void printByEnergy(hangar *Hangar, char botString[], char* energy);

void printBySpecialization(hangar *Hangar, char botString[], char* specialization);

int serviceUndo(operationArray* undo, operationArray* redo, hangar* Hangar);

int serviceRedo(operationArray* undo, operationArray* redo, hangar* Hangar);




