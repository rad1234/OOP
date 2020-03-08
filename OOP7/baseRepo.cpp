#include "baseRepo.h"

int baseRepository::writeToFile()
{
	return 0;
}

int baseRepository::readFromFile(std::string filePath)
{
	return 0;
}

int baseRepository::addPlant(const Plant & plant)
{
	return 0;
}

int baseRepository::readMyListLocation(std::string filePath)
{
	return 0;
}

void baseRepository::setFileName(std::string fileName)
{
}

void baseRepository::setPlantIndex(int plantIndex)
{
}

int baseRepository::removePlant(std::string codedName)
{
	return 0;
}

int baseRepository::updatePlant(const Plant & plant)
{
	return 0;
}

std::vector<Plant> baseRepository::repositoryToService()
{
	return std::vector<Plant>();
}

Plant baseRepository::nextPlantCluster()
{
	return Plant();
}

int baseRepository::repoSave(std::string codedName)
{
	return 0;
}

std::vector<Plant> baseRepository::myList()
{
	return std::vector<Plant>();
}

std::vector<Plant> baseRepository::filterThePlants(std::string species, std::string months)
{
	return std::vector<Plant>();
}

std::vector<Plant> baseRepository::filterThePlantsByMonths(int age)
{
	return std::vector<Plant>();
}
