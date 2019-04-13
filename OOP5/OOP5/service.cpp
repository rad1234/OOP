#include "service.h"
#include "validator.h"
#include "plantCluster.h"
#include "repo.h"

int Service::serviceAdd(char* codedName, char* species, char* months, char* digitizedScan)
{
	Plant newPlant = Plant(codedName, species, months, digitizedScan);

	if (validatePlant(newPlant) == 0)
		return 1;
	
	return this->repository.addPlant(newPlant);

}

int Service::serviceDelete(std::string codedName)
{
	if (codedName == "")
		return 1;

	return this->repository.removePlant(codedName);
}

int Service::serviceUpdate(char * codedName, char * newSpecies, char * newMonths, char * newDigitized)
{
	Plant newPlant = Plant(codedName, newSpecies, newMonths, newDigitized);
	if (validatePlant(newPlant) == 0)
		return 1;

	return this->repository.updatePlant(newPlant);
}

const std::string Service::serviceList()
{
	return this->repository.repoList();
}

const std::string Service::serviceNext()
{
	return this->repository.repoNext();
}

int Service::serviceSave(std::string codedName)
{
	if (codedName == "")
		return 1;
	else
		return this->repository.repoSave(codedName);
}

std::string Service::serviceMyList()
{
	return this->repository.repoMyList();
}

std::string Service::serviceFilter(std::string species, std::string months)
{
	if (months == "")
		return "";
	return this->repository.repoFilter(species, months);
}