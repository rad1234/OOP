#pragma once
#include "plantCluster.h"
#include "dynamicVector.h"
#include <vector>
#include "baseRepo.h"

class Repository : public baseRepository
{
private:
	std::vector<Plant> plants;
	std::vector<Plant> plantsToPurge;
	int plantIndex = 0;
public:
Repository() {}


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