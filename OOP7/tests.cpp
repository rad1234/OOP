#include "tests.h"

void Test::testServiceCreateNewPlantGoodInput()
{
	char codedName[] = "species";
	char species[] = "species";
	char months[] = "3";
	char digitized[] = "scan";
	assert(this->testService.createAndAddPlant(codedName, species, months, digitized) == 0);
}

void Test::testServiceCreateNewPlantBadInput()
{
	char codedName[] = "";
	char species[] = "";
	char months[] = "mdad";
	char digitized[] = "";
	assert(this->testService.createAndAddPlant(codedName, species, months, digitized) == 1);
}

void Test::testServiceDeleteNonExistingPlant()
{
	char codedName[] = "";
	assert(this->testService.deletePlantCluster(codedName) == 1);
}

void Test::testServiceDeleteExistingPlant()
{
	char codedName[] = "1";
	assert(this->testService.deletePlantCluster(codedName) == 0);
}


void Test::testServiceUpdateBadInput()
{
	char codedName[] = "";
	char species[] = "";
	char months[] = "dad";
	char digitized[] = "";
	assert(this->testService.updatePlantCluster(codedName, species, months, digitized) == 1);
}

void Test::testServiceUpdateGoodInput()
{
	char codedName[] = "species";
	char species[] = "species";
	char months[] = "3";
	char digitized[] = "scan";
	assert(this->testService.updatePlantCluster(codedName, species, months, digitized) == 0);
}

void Test::testServiceGetAllPlants()
{
	assert(this->testService.plantsFromRepository().size() > 0);
}

void Test::testServiceNextPlant()
{
	assert(this->testService.returnTheNextPlant().toString() != "");
}

void Test::testServiceSavePlantsBadInput()
{
	assert(this->testService.saveThePlantCluster("") == 1);
}

void Test::testServiceSavePlantsGoodInput()
{
	assert(this->testService.saveThePlantCluster("113") == 0);
}

void Test::testServiceGetPlantsToPurge()
{
	assert(this->testService.returnPlantsToPurge().size() > 0);
}

void Test::testServiceGetFilteredPlantsGoodInput()
{
	assert(this->testService.returnFilteredPlantCluster("ada","5").size() > 0);
}

void Test::testServiceGetFilteredPlantsBadInput()
{
	assert(this->testService.returnFilteredPlantCluster("", "").size() == 0);
}

void Test::testServiceGetFilteredPlantsByMonthsBadInput()
{
	assert(this->testService.returnFilteredPlantsByMonths(-1).size() == 0);
}
void Test::testServiceGetFilteredPlantsByMonthsGoodInput()
{
	assert(this->testService.returnFilteredPlantsByMonths(5).size() > 0);
}

void Test::testFileRepoReadFromFileGood()
{
	std::string fileName = "C:\\Users\\Rares2\\Desktop\\oop\\OOP5\\OOP5\\test4.txt";
	assert(this->fileRepo->readFromFile(fileName) == 0);
}

void Test::testFileRepoReadFromFileBad()
{
	std::string fileName = "";
	assert(this->fileRepo->readFromFile(fileName) == 1);
}

void Test::testFileRepoWriteToGoodFile()
{
	this->fileRepo->setFileName("C:\\Users\\Rares2\\Desktop\\oop\\OOP5\\OOP5\\test0.txt");
	assert(this->fileRepo->writeToFile() == 0);
}

void Test::testFileRepoWriteToBadFile()
{
	this->fileRepo->setFileName("");
	assert(this->fileRepo->writeToFile() == 1);
}

void Test::testFileRepoAdd()
{
	this->fileRepo->setFileName("C:\\Users\\Rares2\\Desktop\\oop\\OOP5\\OOP5\\test.txt");
	Plant testPlant("1", "2", "3", "4");
	assert(this->fileRepo->addPlant(testPlant) == 1);
}

void Test::testFileRepoRemoveGood()
{
	this->fileRepo->setFileName("C:\\Users\\Rares2\\Desktop\\oop\\OOP5\\OOP5\\test1.txt");
	Plant testPlant("1", "2", "3", "4");
	this->fileRepo->addPlant(testPlant);
	assert(this->fileRepo->removePlant("1") == 0);
}

void Test::testFileRepoRemoveBad()
{
	this->fileRepo->setFileName("C:\\Users\\Rares2\\Desktop\\oop\\OOP5\\OOP5\\Plants.txt");
	assert(this->fileRepo->removePlant("1") == 1);
}

void Test::testRepoUpdateGood()
{
	this->fileRepo->setFileName("C:\\Users\\Rares2\\Desktop\\oop\\OOP5\\OOP5\\test5.txt");
	Plant testPlant("1", "2", "3", "4");
	Plant updatePlant("1", "4", "5", "2");
	this->fileRepo->addPlant(testPlant);
	assert(this->fileRepo->updatePlant(updatePlant)==0);
}

void Test::testRepoUpdateBad()
{
	this->fileRepo->setFileName("C:\\Users\\Rares2\\Desktop\\oop\\OOP5\\OOP5\\test6.txt");
	Plant updatePlant("1", "4", "5", "2");
	assert(this->fileRepo->updatePlant(updatePlant)==1);
}

void Test::testRepoGetPlantsGood()
{
	this->fileRepo->setFileName("C:\\Users\\Rares2\\Desktop\\oop\\OOP5\\OOP5\\Plants.txt");
	Plant testPlant("1", "2", "3", "4");
	this->fileRepo->addPlant(testPlant);
	std::vector<Plant> plants = this->fileRepo->repositoryToService();
	assert(plants.size() == 12);
}

void Test::testRepoGetPlantsBad()
{
	std::vector<Plant> plants = this->fileRepo->repositoryToService();

	assert(plants.size() == 12);
}

void Test::testRepoNextPlant()
{
	Plant nextPlant = this->fileRepo->nextPlantCluster();
	assert(nextPlant.getCodedName() == "plant1");

	this->fileRepo->setPlantIndex(2);
	Plant nextPlant1 = this->fileRepo->nextPlantCluster();
}

void Test::testRepoSavePlant()
{
	std::string codedName = "plant1";
	assert(this->fileRepo->repoSave(codedName) == 0);
}

void Test::testRepoMyList()
{
	std::string fileName = "C:\\Users\\Rares2\\Desktop\\oop\\OOP5\\OOP5\\test3.txt";
	std::vector<Plant> plants = this->fileRepo->myList();
	assert(plants.size() == 0);
}

void Test::testFilterThePlants()
{
	std::string fileName = "C:\\Users\\Rares2\\Desktop\\oop\\OOP5\\OOP5\\test3.txt";
	this->fileRepo->readFromFile(fileName);
	std::vector<Plant> filteredPlants = this->fileRepo->filterThePlants("spec", "13");
	assert(filteredPlants.size() == 4);
}

void Test::testFilterThePlantsByAge()
{
	std::string fileName = "C:\\Users\\Rares2\\Desktop\\oop\\OOP5\\OOP5\\test3.txt";
	this->fileRepo->readFromFile(fileName);
	std::vector<Plant> filteredPlants = this->fileRepo->filterThePlantsByMonths(13);
	assert(filteredPlants.size() == 4);
}

void Test::testServiceBadFile()
{
	assert(this->testService.serviceReadTheFile("") == 1);
}

void Test::testServiceGoodFile()
{
	assert(this->testService.serviceReadTheFile("ada") == 0);
}

void Test::testPlantOperator()
{
	Plant p1;
	Plant p2;
	assert(p1 == p2);
}

void Test::testValidatorBad()
{
	assert(this->testValidator.validatePlant(Plant("", "", "", "")) == 0);
	assert(this->testValidator.validatePlant(Plant("1", "", "", "")) == 0);
	assert(this->testValidator.validatePlant(Plant("1", "2", "", "")) == 0);

}


void Test::runAllTests()
{
	this->testValidatorBad();
	this->testPlantOperator();
	this->testServiceBadFile();
	this->testServiceGoodFile();
	this->testRepoMyList();
	this->testFilterThePlantsByAge();
	this->testFilterThePlants();
	this->testServiceCreateNewPlantGoodInput();
	this->testServiceCreateNewPlantBadInput();
	this->testServiceDeleteExistingPlant();
	this->testServiceDeleteNonExistingPlant();
	this->testServiceGetAllPlants();
	this->testServiceNextPlant();
	this->testServiceSavePlantsBadInput();
	this->testServiceSavePlantsGoodInput();
	this->testServiceUpdateBadInput();
	this->testServiceUpdateGoodInput();
	this->testServiceGetPlantsToPurge();
	this->testServiceGetFilteredPlantsGoodInput();
	this->testServiceGetFilteredPlantsBadInput();
	this->testServiceGetFilteredPlantsByMonthsGoodInput();
	this->testServiceGetFilteredPlantsByMonthsBadInput();
	this->testFileRepoReadFromFileBad();
	this->testFileRepoReadFromFileGood();
	this->testFileRepoWriteToBadFile();
	this->testFileRepoWriteToGoodFile();
	this->testFileRepoAdd();
	this->testFileRepoRemoveGood();
	this->testFileRepoRemoveBad();
	this->testRepoUpdateBad();
	this->testRepoUpdateGood();
	this->testRepoGetPlantsGood();
	this->testRepoGetPlantsBad();
	this->testRepoNextPlant();
	this->testRepoSavePlant();
}