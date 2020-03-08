#pragma once
#include "repo.h"
#include "validator.h"
class Service
{
private:
	baseRepository* repository;
	Validator validator;

public:
	Service (baseRepository* initRepository, Validator initValidator) : repository{ initRepository }, validator{ initValidator } {};
	Service();
	
	int createAndAddPlant(char * codedName, char * species, char * months, char * digitizedScan);

	int deletePlantCluster(std::string codedName);

	int updatePlantCluster(char* codedName,char* newSpecies,char* newMonths,char* newDigitized);

	std::vector<Plant> plantsFromRepository();

	Plant returnTheNextPlant();
	int saveThePlantCluster(std::string codedName);
	std::vector<Plant> returnPlantsToPurge();
	std::vector<Plant> returnFilteredPlantCluster(std::string species, std::string months);
	int serviceReadTheFile(std::string filePath);
	int serviceReadMyListLocation(std::string filePath);
	std::vector<Plant> returnFilteredPlantsByMonths(int age);
};

