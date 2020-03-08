#pragma once
#include "plantCluster.h"
#include <vector>
#include <string>
class baseRepository
{
public:
	baseRepository() {};
	virtual int writeToFile();

	virtual int readFromFile(std::string filePath);
	virtual int addPlant(const Plant & plant);

	virtual int readMyListLocation(std::string filePath);

	virtual int readMyListLocationHTML(std::string filePath);

	virtual void setFileName(std::string fileName);

	virtual void setPlantIndex(int plantIndex);

	virtual int removePlant(std::string codedName);

	virtual int updatePlant(const Plant & plant);

	virtual std::vector<Plant> repositoryToService();

	virtual Plant nextPlantCluster();
	virtual int repoSave(std::string codedName);
	virtual std::vector<Plant> myList();
	virtual std::vector<Plant> filterThePlants(std::string species, std::string months);
	virtual std::vector<Plant> filterThePlantsByMonths(int age);
};