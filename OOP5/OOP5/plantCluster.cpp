#pragma once
#include "plantCluster.h"
#include <string.h>

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

bool operator==(const Plant & p1, const Plant & p2)
{
	return (p1.getCodedName() == p2.getCodedName());
}
