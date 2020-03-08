#include "service.h"
#include "validator.h"
#include "plantCluster.h"
#include "repo.h"
#include <iostream>
#include "fileRepo.h"
using namespace std;



int Service::createAndAddPlant(char* codedName, char* species, char* months, char* digitizedScan)
{
	Plant newPlant = Plant(codedName, species, months, digitizedScan);

	if (this->validator.validatePlant(newPlant) == 0)
		return 1;

	return this->repository->addPlant(newPlant);

}

int Service::deletePlantCluster(std::string codedName)
{
	if (codedName == "")
		return 1;

	return this->repository->removePlant(codedName);
}

int Service::updatePlantCluster(char * codedName, char * newSpecies, char * newMonths, char * newDigitized)
{
	Plant newPlant = Plant(codedName, newSpecies, newMonths, newDigitized);
	if (this->validator.validatePlant(newPlant) == 0)
		return 1;

	return this->repository->updatePlant(newPlant);
}

std::vector<Plant> Service::plantsFromRepository()
{
	return this->repository->repositoryToService();
}



Plant Service::returnTheNextPlant()
{
	return this->repository->nextPlantCluster();
}

int Service::saveThePlantCluster(std::string codedName)
{
	if (codedName == "")
		return 1;

	return this->repository->repoSave(codedName);
}

std::vector<Plant> Service::returnPlantsToPurge()
{
	return this->repository->myList();
}

std::vector<Plant> Service::returnFilteredPlantCluster(std::string species, std::string months)
{
	std::vector<Plant> empty;
	if (species == "" || months == "")
		return empty;
	return this->repository->filterThePlants(species, months);
}

int Service::serviceReadTheFile(std::string filePath)
{
	if (filePath == "")
		return 1;

	return this->repository->readFromFile(filePath);
}

int Service::serviceReadMyListLocation(std::string filePath)
{
	if (filePath == "")
		return 1;

	return this->repository->readMyListLocation(filePath);
}

std::vector<Plant> Service::returnFilteredPlantsByMonths(int age)
{
	std::vector<Plant> empty;
	if (age < 0)
		return empty;
	return this->repository->filterThePlantsByMonths(age);
}

