#pragma once
#include "fakeRepo.h"
#include "service.h"
#include "validator.h"
#include <assert.h>

class Test
{
private:
	baseRepository* fileRepo;
	baseRepository* testRepo;
	Service testService;
	Validator testValidator;
public:
	Test(baseRepository* initFile, baseRepository* initTestRepo, Service initTestService, Validator initTestValidator) : fileRepo{ initFile }, testRepo { initTestRepo }, testService{ initTestService }, testValidator{ initTestValidator }{}
	void testServiceCreateNewPlantGoodInput();
	void testServiceCreateNewPlantBadInput();
	void testFileRepoWriteToGoodFile();
	void testFileRepoWriteToBadFile();
	void testFileRepoAdd();
	void testFileRepoRemoveGood();
	void testFileRepoRemoveBad();
	void testRepoUpdateGood();
	void testRepoUpdateBad();
	void testRepoGetPlantsGood();
	void testRepoGetPlantsBad();
	void testRepoNextPlant();
	void testRepoSavePlant();
	void testRepoMyList();
	void testFilterThePlants();
	void testFilterThePlantsByAge();
	void testServiceBadFile();
	void testServiceGoodFile();
	void testPlantOperator();
	void testValidatorBad();
	void runAllTests();

	void testServiceDeleteNonExistingPlant();

	void testServiceDeleteExistingPlant();

	void testServiceUpdateBadInput();

	void testServiceUpdateGoodInput();

	void testServiceGetAllPlants();

	void testServiceNextPlant();

	void testServiceSavePlantsBadInput();

	void testServiceSavePlantsGoodInput();

	void testServiceGetPlantsToPurge();

	void testServiceGetFilteredPlantsGoodInput();

	void testServiceGetFilteredPlantsBadInput();

	void testServiceGetFilteredPlantsByMonthsBadInput();

	void testServiceGetFilteredPlantsByMonthsGoodInput();

	void testFileRepoReadFromFileGood();

	void testFileRepoReadFromFileBad();


};