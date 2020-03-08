#pragma once
#include "baseRepo.h"
class fakeRepo :public baseRepository
{

public:
	fakeRepo(){}
	int addPlant(const Plant & plant) override;
	int removePlant(std::string codedName) override;
	int updatePlant(const Plant &plant) override;
	std::vector<Plant> repositoryToService() override;
	Plant nextPlantCluster() override;
	int repoSave(std::string codedName)override;
	std::vector<Plant> myList() override;
	std::vector<Plant> filterThePlants(std::string species, std::string months) override;
	std::vector<Plant> filterThePlantsByMonths(int age) override;
};
