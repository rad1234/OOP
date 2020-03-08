#include "fakeRepo.h"

int fakeRepo::addPlant(const Plant & plant)
{
	return 0;
}

int fakeRepo::removePlant(std::string codedName)
{
	return 0;
}

int fakeRepo::updatePlant(const Plant & plant)
{
	return 0;
}

std::vector<Plant> fakeRepo::repositoryToService()
{
	std::vector<Plant> plasticPlants;
	std::string codedName = "abc";
	std::string species = "plastic";
	std::string months = "not alive";
	std::string digitized = "not a damn plant";
	Plant plantie(codedName, species, months, digitized);
	plasticPlants.push_back(plantie);

	return plasticPlants;
}

Plant fakeRepo::nextPlantCluster()
{
	std::string codedName = "abc";
	std::string species = "plastic";
	std::string months = "not alive";
	std::string digitized = "not a damn plant";
	Plant plantie(codedName, species, months, digitized);

	return plantie;
}

int fakeRepo::repoSave(std::string codedName)
{
	return 0;
}

std::vector<Plant> fakeRepo::myList()
{
	std::vector<Plant> plasticPlants;
	std::string codedName = "abc";
	std::string species = "plastic";
	std::string months = "not alive";
	std::string digitized = "not a damn plant";
	Plant plantie(codedName, species, months, digitized);
	plasticPlants.push_back(plantie);

	return plasticPlants;
}

std::vector<Plant> fakeRepo::filterThePlants(std::string species, std::string months)
{
	std::vector<Plant> plasticPlants;
	std::string codedName = "abc";
	std::string speciesPlant = "plastic";
	std::string monthsPlant = "not alive";
	std::string digitized = "not a damn plant";
	Plant plantie(codedName, species, months, digitized);
	plasticPlants.push_back(plantie);

	return plasticPlants;
}

std::vector<Plant> fakeRepo::filterThePlantsByMonths(int age)
{
	std::vector<Plant> plasticPlants;
	std::string codedName = "abc";
	std::string species = "plastic";
	std::string months = "not alive";
	std::string digitized = "not a damn plant";
	Plant plantie(codedName, species, months, digitized);
	plasticPlants.push_back(plantie);

	return plasticPlants;
}

