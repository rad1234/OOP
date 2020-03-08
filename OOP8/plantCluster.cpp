#pragma once
#include "plantCluster.h"
#include <string.h>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
Plant::Plant(): codedName(""),species(""),months(""),digitizedScan(""){}

Plant::Plant(const std::string codedName, const std::string species, const std::string months, const std::string digitizedScan)
{
	this->codedName = codedName;
	this->species = species;
	this->months = months;
	this->digitizedScan = digitizedScan;
}



std::string Plant::toString() const
{
	std::string toString = "";
	toString += this->getCodedName();
	toString += " ";
    toString += this->getSpecies();
	toString += " ";
	toString += this->getMonths();
	toString += " ";
	toString += this->getScan();
	toString += "\n";
	return toString;
}

bool operator==(const Plant & firstPlant, const Plant & secondPlant)
{
	return (firstPlant.getCodedName() == secondPlant.getCodedName());
}


std::istream & operator>>(std::istream & is, Plant & plantie)
{
	std::string line;
	getline(is, line);

	std::stringstream stringStreamSplit(line);
	std::string tokenAfterSplit;
	std::vector<std::string> spilttedLine;
	std::string codedName, species, months, digitizedScan;
	while (std::getline(stringStreamSplit, tokenAfterSplit, ','))
		spilttedLine.push_back(tokenAfterSplit);
	
		if (spilttedLine.size() != 4)
			return is;

		plantie.codedName = spilttedLine[0];
		plantie.species = spilttedLine[1];
		plantie.months = spilttedLine[2];
		plantie.digitizedScan = spilttedLine[3];

	return is;

}
 
std::ostream & operator<<(std::ostream & os, const Plant & plantie)
{
	os << plantie.codedName << "," << plantie.species << "," << plantie.months << "," << plantie.digitizedScan << "\n";
	return os;
}