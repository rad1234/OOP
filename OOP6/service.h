#pragma once
#include "repo.h"

class Service
{
private:
	Repository repository;

public:
	Service(const Repository& initRepository) : repository(initRepository) {};
	
	int serviceAdd(char * codedName, char * species, char * months, char * digitizedScan);

	int serviceDelete(std::string codedName);

	int serviceUpdate(char* codedName,char* newSpecies,char* newMonths,char* newDigitized);

	const std::string serviceList();

	const std::string serviceNext();
	int serviceSave(std::string codedName);
	const std::string serviceMyList();
	const std::string serviceFilter(std::string species, std::string months);
	const std::string serviceFilterOneParam(int age);
};

