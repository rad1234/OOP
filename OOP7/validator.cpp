#include "plantCluster.h"
#include "string"
#include "validator.h"


int Validator::validatePlant(Plant plantie)
{
	if (plantie.getCodedName() == "")
		return 0;
	if (plantie.getSpecies() == "")
		return 0;
	if (plantie.getScan() == "")
		return 0;
	try
	{
		int n = std::stoi(plantie.getMonths());
	}
	catch(int e)
	{
		throw 0;
	}

	return 1;

}
