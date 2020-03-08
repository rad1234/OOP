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
		
		throw RepositoryException("The file could not be opend!");
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

int fileRepository::readMyListLocationHTML(std::string filePath)
{
	this->htmlFileName = filePath;
	return 0;
}


int fileRepository::readFromFile(std::string fileName)
{
	this->fileName = fileName;
	std::ifstream readFile;
	readFile.open(this->fileName, std::ios::app);

	

	if (!readFile.is_open())
	{
		throw RepositoryException("The file could not be opend!");
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
			throw RepositoryException("The plant exists!");

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

	throw RepositoryException("The plant could not be removed");

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

	throw RepositoryException("The plant could not be updated!");
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

	std::ofstream writeFile;

	if (this->csvFileName != "")
	{
		writeFile.open(this->csvFileName, std::ios::trunc);

		if (!writeFile.is_open())
		{
			throw RepositoryException("The file could not be opend!");
			
		}

		for (auto plantie : this->plantsToPurge)
		{
			writeFile << plantie;
		}
		writeFile.close();

		this->openTheFiles();
	}

	if (this->htmlFileName != "")
	{
		std::ofstream outputStream(this->htmlFileName);

		outputStream << "<!DOCTYPE html>\n";
		outputStream << "<html>\n";
		outputStream << "<head><title>Plants</title></head>\n";
		outputStream << "<body>\n";
		outputStream << "<table border=\"1\">\n";

		outputStream << "<tr>\n";
		outputStream << "<td>Coded Name</td>\n";
		outputStream << "<td>Species</td>\n";
		outputStream << "<td>Age</td>\n";
		outputStream << "<td>Scan</td>\n";
		outputStream << "</tr>\n";

		for (auto const& plantie : this->plantsToPurge) {
			outputStream << "<tr>\n";
			outputStream << "<td>" << plantie.getCodedName() << "</td>\n";
			outputStream << "<td>" << plantie.getSpecies() << "</td>\n";
			outputStream << "<td>" << plantie.getMonths() << "</td>\n";
			outputStream << "<td>" << plantie.getScan() << "</td>\n";
			outputStream << "</tr>\n";
		}

		outputStream << "</table>\n";
		outputStream << "</body>\n";
		outputStream << "</html>\n";

		outputStream.close();

		return 0;
	}
}

void fileRepository::openTheFiles()
{
	if (this->htmlFileName != "")
	{
		std::string path = "\"" + this->htmlFileName+ "\"";
		//ShellExecuteA(NULL, NULL, "C:\\Program Files\\Opera\\launcher.exe", path.c_str(), NULL, SW_SHOWMAXIMIZED);
	}
	if (this->csvFileName != "")
	{
		std::string path = "\"" + this->csvFileName + "\"";
		//ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\Microsoft Office\\root\\Office16\\EXCEL.EXE", path.c_str(), NULL, SW_SHOWMAXIMIZED);
	}
	
}

std::vector<Plant> fileRepository::myList()
{
	std::vector<Plant> emptyPlantCluster;
	std::ofstream writeFile;

	if (this->csvFileName != "")
	{
		writeFile.open(this->csvFileName, std::ios::trunc);

		if (!writeFile.is_open())
		{
			throw RepositoryException("The file could not be opend!");
			return emptyPlantCluster;
		}

		for (auto plantie : this->plantsToPurge)
		{
			writeFile << plantie;
		}
		writeFile.close();
		
		this->openTheFiles();
	}

	if (this->htmlFileName != "")
	{
		std::ofstream outputStream(this->htmlFileName);

		outputStream << "<!DOCTYPE html>\n";
		outputStream << "<html>\n";
		outputStream << "<head><title>Plants</title></head>\n";
		outputStream << "<body>\n";
		outputStream << "<table border=\"1\">\n";

		outputStream << "<tr>\n";
		outputStream << "<td>Coded Name</td>\n";
		outputStream << "<td>Species</td>\n";
		outputStream << "<td>Age</td>\n";
		outputStream << "<td>Scan</td>\n";
		outputStream << "</tr>\n";

		for (auto const& plantie : this->plantsToPurge) {
			outputStream << "<tr>\n";
			outputStream << "<td>" << plantie.getCodedName()<< "</td>\n";
			outputStream << "<td>" << plantie.getSpecies() << "</td>\n";
			outputStream << "<td>" << plantie.getMonths() << "</td>\n";
			outputStream << "<td>" << plantie.getScan() << "</td>\n";
			outputStream << "</tr>\n";
		}

		outputStream << "</table>\n";
		outputStream << "</body>\n";
		outputStream << "</html>\n";

		outputStream.close();

		this->openTheFiles();
	}

	
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

