#include "fileRepo.h"
#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>

int fileRepository::writeToFile()
{
	std::ofstream writeFile;
	writeFile.open(this->fileName, std::ios::trunc);

	if (!writeFile.is_open())
	{
		std::cout << ("The file could not be opened!");
		return 1;
	}

	for (auto plantie : this->plants)
	{
		writeFile << plantie;
	}

	writeFile.close();
	return 0;
}

int fileRepository::readMyListLocation(std::string filePath)
{
	this->csvFileName = filePath;
	return 0;
}


int fileRepository::readFromFile(std::string fileName)
{
	this->fileName = fileName;
	std::ifstream readFile;
	readFile.open(this->fileName, std::ios::app);

	

	if (!readFile.is_open())
	{
		std::cout << "The file could not be opened!";
		return 1;
	}
	

	Plant plantie;
	while (readFile >> plantie)
		this->plants.push_back(plantie);

	readFile.close();
	return 0;
}


int fileRepository::addPlant(const Plant & plant)
{
	for (auto plantie : this->plants)
		if (plantie.getCodedName() == plant.getCodedName())
			return 1;

	this->plants.push_back(plant);

	this->writeToFile();

	return 0;
}

int fileRepository::removePlant(std::string codedName)
{
	bool found = false;
	for (int index = 0; index < plants.size(); index++)
		if (this->plants[index].getCodedName() == codedName)
		{
			found = true;
			this->plants.erase(this->plants.begin() + index);
			this->writeToFile();
			return 0;
		}

	return 1;

}

int fileRepository::updatePlant(const Plant & plant)
{
	for (auto& plantie : this->plants)
		if (plantie.getCodedName() == plant.getCodedName())
		{
			plantie = plant;
			this->writeToFile();
			return 0;
		}

	return 1;
}

std::vector<Plant> fileRepository::repositoryToService()
{
	return this->plants;
}

Plant fileRepository::nextPlantCluster()
{

	Plant nextPlant = plants[this->plantIndex];
	this->plantIndex++;
	if (this->plantIndex == plants.size())
		this->plantIndex = 0;
	return nextPlant;
}

int fileRepository::repoSave(std::string codedName)
{
	Plant goodPlantie;
	for (auto plantie : this->plants)
	{
		if (plantie.getCodedName() == codedName)
		{
			goodPlantie = plantie;
			break;
		}
	}
	
	plantsToPurge.push_back(goodPlantie);
	return 0;
}

std::vector<Plant> fileRepository::myList()
{
	std::vector<Plant> emptyPlantCluster;
	std::ofstream writeFile;
	writeFile.open(this->csvFileName, std::ios::trunc);

	if (!writeFile.is_open())
	{
		std::cout << ("The file could not be opened!");
		return emptyPlantCluster;
	}

	for (auto plantie : this->plantsToPurge)
	{
		writeFile << plantie;
	}

	writeFile.close();
	return this->plantsToPurge;
}

std::vector<Plant> fileRepository::filterThePlants(std::string species, std::string months)
{
	std::vector< Plant> goodPlants;
	int jndex = 0;
	for (auto plantie : this->plants)
	{
		if (plantie.getSpecies() == species)
		{
			if (stoi(plantie.getMonths()) < stoi(months))
			{
				goodPlants.push_back(plantie);
			}
		}
	}
	return goodPlants;
}

std::vector<Plant> fileRepository::filterThePlantsByMonths(int age)
{
	std::vector<Plant> goodPlants;
	int jndex = 0;
	for (auto plantie : this->plants)
	{

		if (stoi(plantie.getMonths()) < age)
			goodPlants.push_back(plantie);

	}
	return goodPlants;
}

