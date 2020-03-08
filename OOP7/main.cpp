#include "UI.h"
#include "fakeRepo.h"
#include "baseRepo.h"
#include "tests.h"
#include "fileRepo.h"
int main()
{
	//baseRepository* repository = new Repository{};
	Validator validator;
	baseRepository* fileRepo = new fileRepository{};
	Service controller{ fileRepo,validator };
	//baseRepository* testRepository = new fakeRepo{};
	//Service testController{ testRepository,validator };
	//Test testService(fileRepo,testRepository, testController, validator);
	//testService.runAllTests();
	//delete testRepository;
	UI ui{controller};
	ui.run();
	//delete repository;
	delete fileRepo;
	return 0;


}

