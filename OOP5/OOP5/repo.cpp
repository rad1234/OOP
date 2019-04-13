#include "repo.h"
#include <string>
#include <iostream>

int Repository::addPlant(const Plant & plant)
{
	int size = this->plants.getSize();
	for (int index = 0; index < size; index++)
		if (this->plants[index].getCodedName() == plant.getCodedName())
			return 1;

	this->plants.add(plant);

	return 0;
}

int Repository::removePlant(std::string codedName)
{
	int size = this->plants.getSize();
	bool found = false;
	for (int index = 0; index < size; index++)
		if (this->plants[index].getCodedName() == codedName)
		{
			found = true;
			this->plants.remove(this->plants[index]);
			return 0;
		}

	if (found == false)
		return 1;

	return 1;
			
}

int Repository::updatePlant(const Plant & plant)
{
	int size = this->plants.getSize();
	for (int index = 0; index < size; index++)
		if (this->plants[index].getCodedName() == plant.getCodedName())
		{
			this->plants[index] = plant;
			return 0;
		}

	return 1;
}

const std::string Repository::repoList()
{
	std::string stringToPrint = "";
	int size = this->plants.getSize();
	for (int index = 0; index < size; index++)
	{
	  stringToPrint += this->plants[index].toString();
	}

	return stringToPrint;

}

const std::string Repository::repoNext()
{
	
	Plant nextPlant = plants[this->plantIndex];
	std::string plantString = nextPlant.toString();
	this->plantIndex++;
	if (this->plantIndex == plants.getSize())
		this->plantIndex = 0;
	return plantString;

}

int Repository::repoSave(std::string codedName)
{
	
	if (this->plantIndex != 0)
		this->plantIndex--;
		for (int index = 0; index < plantsToPurge.getSize(); index++)
		{
			if (plantsToPurge[index].getCodedName() == codedName)
				return 1;
		}
		Plant temporaryPlantie = plants[this->plantIndex];
		plantsToPurge.add(temporaryPlantie);
	if(this->plantIndex != 0)
		this->plantIndex++;
	return 0;
}

const std::string Repository::repoMyList()
{
	std::string stringToPrint = "";
	int size = this->plantsToPurge.getSize();
	for (int index = 0; index < size; index++)
	{
		stringToPrint += this->plantsToPurge[index].toString();
	}

	return stringToPrint;
}

const std::string Repository::repoFilter(std::string species, std::string months)
{
	std::string goodPlants = "";
	int ageToCompare = 0, monthsOfPlant = 0;
	if(species!="")
		for (int index = 0; index < this->plants.getSize(); index++)
		{
			if (this->plants[index].getSpecies() == species)
			{
				if (this->plants[index].getMonths() < months)
					goodPlants += this->plants[index].toString();
			}
		}
	else if(species == "")
		for (int index = 0; index < this->plants.getSize(); index++)
		{
			if (this->plants[index].getMonths() < months)
				goodPlants += this->plants[index].toString();
		}
	return goodPlants;
}


