#pragma once
#include "repo.h"
class fileRepository : public Repository
{
private:
	std::vector<Plant> plants;
	std::vector<Plant> plantsToPurge;
	int plantIndex = 0;
	std::string fileName;
	std::string csvFileName;
public:
	fileRepository() {}


	int writeToFile() override;

	int readMyListLocation(std::string filePath) override;

	void setFileName(std::string fileName) override { this->fileName = fileName; }

	void setPlantIndex(int plantIndex) override { this->plantIndex = plantIndex; }

	int readFromFile(std::string ) override;

	int addPlant(const Plant & plant) override;

	int removePlant(std::string codedName) override;
	int updatePlant(const Plant & plant) override;

	std::vector<Plant> repositoryToService() override;
	Plant nextPlantCluster() override;
	int repoSave(std::string codedName) override;
	std::vector<Plant> myList() override;
	std::vector<Plant> filterThePlants(std::string species, std::string months) override;
	std::vector<Plant> filterThePlantsByMonths(int age) override;
};