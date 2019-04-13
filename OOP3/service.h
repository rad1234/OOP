#pragma once
#include <stdio.h>
#include <string.h>
#include "Repo.h"


int serviceAdd(hangar *Hangar,char serialNumber[], char state[], char specialization[], char energyCapacity[]);

int serviceUpdate(hangar *Hangar, char serialNumber[], char newState[], char newSpecialization[], char newEnergyCapacity[]);

int serviceDelete(hangar *Hangar, char serialNumber[]);

const char* serviceListAll(hangar *Hangar);

const char* serviceListSpecial(hangar *Hangar, char specialization[]);
