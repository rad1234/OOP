#include <iostream>
#include "UI.h"
#include "service.h"
using namespace std;
#include <string>



int UI::uiAdd(char* parameters)
{
	char codedName[20], species[20], months[20], digitizedScan[20];
	parameters = strtok(NULL, ", ");
	
	if (parameters == NULL)
		return 1;
	strcpy(codedName, parameters);
	parameters = strtok(NULL, ", ");
	if (parameters == NULL)
		return 1;
	strcpy(species, parameters);
	parameters = strtok(NULL, ", ");
	if (parameters == NULL)
		return 1;
	strcpy(months, parameters);
	parameters = strtok(NULL, ", ");
	if (parameters == NULL)
		return 1;
	strcpy(digitizedScan, parameters);
	parameters = strtok(NULL, ", ");
	if (parameters != NULL)
		return 1;
	return controller.createAndAddPlant(codedName, species, months, digitizedScan);
}

int UI::uiDelete(char* parameters)
{
	char codedName[20];
	parameters = strtok(NULL, " ");
	if (parameters == NULL)
		return 1;
	strcpy(codedName, parameters);
	parameters = strtok(NULL, " ");
	if (parameters != NULL)
		return 1;

	return controller.deletePlantCluster(codedName);
}

int UI::uiUpdate(char* parameters)
{
	char codedName[20], newSpecies[20], newMonths[20], newDigitized[20];
	parameters = strtok(NULL, ", ");
	if (parameters == NULL)
		return 1;
	strcpy(codedName, parameters);
	parameters = strtok(NULL, ", ");
	if (parameters == NULL)
		return 1;
	strcpy(newSpecies, parameters);
	parameters = strtok(NULL, ", ");
	if (parameters == NULL)
		return 1;
	strcpy(newMonths, parameters);
	parameters = strtok(NULL, ", ");
	if (parameters == NULL)
		return 1;
	strcpy(newDigitized, parameters);
	parameters = strtok(NULL, "");
	if (parameters != NULL)
		return 1;

	return controller.updatePlantCluster(codedName, newSpecies,newMonths, newDigitized);

}

int UI::uiList()
{
	std::vector<Plant> plants = this->controller.plantsFromRepository();
	for (auto plantie : plants)
	{
		std::string plantieString = plantie.toString();
		cout << plantieString;
	}
	return 0;
}


int UI::makeAdmin(char* parameters)
{
	parameters = strtok(NULL, " ");
	if (strcmp(parameters, "A") == 0)
	{
		cout << "Admin mode, enabled!\n";
		return 1;
	}
	else if (strcmp(parameters, "B") == 0)
	{
		cout << "Assistant mode, enabled!\n";
		return 0;

	}
	return -1;
}

void UI::uiError()
{
	cout << "Engineering Terminal's local AI:\n...Something caused an unexpected result...\n";
}

int UI::uiNext()
{
	Plant plantie = controller.returnTheNextPlant();
	if (plantie.toString() == "")
		return 1;
	else
	{
		cout << plantie.toString();
		return 0;
	}
}

int UI::uiSave(char* parameters)
{
	char* codedName = strtok(NULL, " ");

	return controller.saveThePlantCluster(codedName);


}

int UI::uiMyList()
{
	std::vector<Plant> savedPlants = controller.returnPlantsToPurge();
	for(auto plantie:savedPlants)
		cout << plantie.toString();
	
	return 0;
}

bool isNumber(string s)
{
	for (int i = 0; i < s.length(); i++)
		if (isdigit(s[i]) == false)
			return false;

	return true;
}

int UI::uiAssistantList(char* parameters)
{
	char* species = strtok(NULL, ", ");
	char* months = strtok(NULL, ", ");
	int age = 0;
	std::vector<Plant> filteredPlants;
	if (isNumber(species))
	{
		age = stoi(species);
		filteredPlants = controller.returnFilteredPlantsByMonths(age);
	}
	else
	{
		filteredPlants = controller.returnFilteredPlantCluster(species, months);
	}
	
	if (filteredPlants.size() == 0)
		return 1;

	for (auto plantie:filteredPlants)
		cout << plantie.toString();
	return 0;
}

int UI::readTheFile(char* parameters)
{
	parameters = strtok(NULL, "");
	char filePath[255];
	strcpy(filePath, parameters);
	std::cout << filePath;
	return controller.serviceReadTheFile(filePath);
}

int UI::myListFile(char* parameters)
{
	parameters = strtok(NULL, "");
	char filePath[255];
	strcpy(filePath, parameters);
	std::cout << filePath;
	return controller.serviceReadMyListLocation(filePath);
}

void UI::run()
{
	int isAdmin = 0;
	int isAssistant = 1;
	int mode = -1;
	int plantIndex = 0;
	int isError;
	while (1)
	{
		char command[100], action[50];
		char* parameters;
		if (mode == -1)
		{
			isError = 0;
			cout << "Engineering Terminal's local AI:\n...Pick a mode of command...\n";
			cin.getline(command,100);
			parameters = strtok(command, ", ");
			strcpy(action, parameters);
			if (strcmp(action, "mode") == 0)
				mode = makeAdmin(parameters);
			else if (strcmp(action, "fileLocation") == 0)
				isError = readTheFile(parameters);
			else if (strcmp(action, "mylistLocation") == 0)
				isError = myListFile(parameters);
			else if (strcmp(action, "exit") == 0)
				return;
		}
		if(mode == 1)
		{
			isError = 1;
			cout << "Engineering Terminal's local AI:\n......Please input your command...\n";
			cin.getline(command,100);
			parameters = strtok(command, ", ");
			strcpy(action, parameters);
			if (strcmp(action, "add") == 0)
				isError = uiAdd(parameters);
			else if (strcmp(action, "delete") == 0)
				isError = uiDelete(parameters);
			else if (strcmp(action, "fileLocation")==0)
				isError = readTheFile(parameters);
			else if (strcmp(action, "update") == 0)
				isError = uiUpdate(parameters);
			else if (strcmp(action, "list") == 0)
				isError = uiList();
			else if (strcmp(action, "exit") == 0)
				return;
			else if (strcmp(action, "mode") == 0)
				mode = makeAdmin(parameters);
		}

		if (mode == 0)
		{
			
			isError = 1;
			cout<< "Engineering Terminal's local AI:\n......Please input your command...\n";
			cin.getline(command, 50);
			parameters = strtok(command, ", ");
			strcpy(action, parameters);
			if (strcmp(action, "next") == 0)
			{
				isError = uiNext();
			}
			else if (strcmp(action, "save") == 0)
				isError = uiSave(parameters);
			else if (strcmp(action, "mylist") == 0)
				isError = uiMyList();
			else if (strcmp(action, "list") == 0)
				isError = uiAssistantList(parameters);
			else if (strcmp(action, "mode") == 0)
				mode = makeAdmin(parameters);
			else if (strcmp(action, "mylistLocation") == 0)
				isError = myListFile(parameters);
			else if (strcmp(action, "exit") == 0)
				return;

		}

		if (isError == 1)
			uiError();
	}
}

