#pragma once
#include "plantCluster.h"
#include "dynamicVector.h"

class Repository
{
private:
	dynamicVector<Plant> plants;
	dynamicVector<Plant> plantsToPurge;
	int plantIndex = 0;
public:
Repository() {}


int addPlant(const Plant & plant);

int removePlant(std::string codedName);

int updatePlant(const Plant & plant);

const std::string repoList();

const std::string repoNext();
int repoSave(std::string codedName);
const std::string repoMyList();
const std::string repoFilter(std::string species, std::string months);
};