#include "repo.h"
#include <string>
#include <iostream>

int Repository::addPlant(const Plant & plant)
{
	for (auto plantie:this->plants)
		if (plantie.getCodedName() == plant.getCodedName())
			return 1;

	this->plants.push_back(plant);

	return 0;
}

int Repository::removePlant(std::string codedName)
{
	bool found = false;
	for (int index = 0;index<plants.size();index++)
		if (this->plants[index].getCodedName() == codedName)
		{
			found = true;
			this->plants.erase(this->plants.begin() + index);
			return 0;
		}

	if (found == false)
		return 1;

	return 1;
			
}

int Repository::updatePlant(const Plant & plant)
{
	for (auto& plantie:this->plants)
		if (plantie.getCodedName() == plant.getCodedName())
		{
			plantie = plant;
			return 0;
		}

	return 1;
}

std::vector<Plant> Repository::repositoryToService()
{
	return this->plants;
}

Plant Repository::nextPlantCluster()
{
	
	Plant nextPlant = plants[this->plantIndex];
	this->plantIndex++;
	if (this->plantIndex == plants.size())
		this->plantIndex = 0;
	return nextPlant;
}

int Repository::repoSave(std::string codedName)
{
	
	if (this->plantIndex != 0)
		this->plantIndex--;
		for (auto plantie: this->plantsToPurge)
		{
			if (plantie.getCodedName() == codedName)
				break;
		}
		Plant temporaryPlantie = plants[this->plantIndex];
		plantsToPurge.push_back(temporaryPlantie);
	if(this->plantIndex != 0)
		this->plantIndex++;
	return 0;
}

std::vector<Plant> Repository::myList()
{
	return this->plantsToPurge;
}

std::vector<Plant> Repository::filterThePlants(std::string species, std::string months)
{
	std::vector< Plant> goodPlants;
	int jndex = 0;
		for (auto plantie: this->plants)
		{
			if (plantie.getSpecies() == species)
			{
				if (stoi(plantie.getMonths()) < stoi(months))
				{
					goodPlants[jndex++] = plantie;	
				}
			}
		}
	return goodPlants;
}

std::vector<Plant> Repository::filterThePlantsByMonths(int age)
{
	std::vector<Plant> goodPlants;
	int jndex = 0;
	for(auto plantie : this->plants)
	{

			if (stoi(plantie.getMonths()) < age)
				goodPlants[jndex++] = plantie;
		
	}
	return goodPlants;
}

