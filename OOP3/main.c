#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "service.h"
#include "Repo.h"
#include <stdlib.h>

int uiAdd(hangar *Hangar, char* parameters)
{
	char serialNumber[20], state[20], specialization[20], energyCapacity[20];
	parameters = strtok(NULL, " ");
	if (parameters == NULL)
		return 1;
	strcpy(serialNumber, parameters);
	parameters = strtok(NULL, " ");
	if (parameters == NULL)
		return 1;
	strcpy(state, parameters);
	parameters = strtok(NULL, " ");
	if (parameters == NULL)
		return 1;
	strcpy(specialization, parameters);
	parameters = strtok(NULL, " ");
	if (parameters == NULL)
		return 1;
	strcpy(energyCapacity, parameters);
	parameters = strtok(NULL, " ");
	if (parameters != NULL)
		return 1;

	return serviceAdd(Hangar, serialNumber, state, specialization, energyCapacity);

}

int uiUpdate(hangar *Hangar, char* parameters)
{
	char serialNumber[20], newState[20], newSpecialization[20], newEnergyCapacity[20];
	parameters = strtok(NULL, " ");
	if (parameters == NULL)
		return 1;
	strcpy(serialNumber, parameters);
	parameters = strtok(NULL, " ");
	if (parameters == NULL)
		return 1;
	strcpy(newState, parameters);
	parameters = strtok(NULL, " ");
	if (parameters == NULL)
		return 1;
	strcpy(newSpecialization, parameters);
	parameters = strtok(NULL, " ");
	if (parameters == NULL)
		return 1;
	strcpy(newEnergyCapacity, parameters);
	parameters = strtok(NULL, " ");
	if (parameters != NULL)
		return 1;
	
	return serviceUpdate(Hangar, serialNumber, newState, newSpecialization, newEnergyCapacity);

}

int uiDelte(hangar *Hangar, char* parameters)
{
	char serialNumber[20];
	parameters = strtok(NULL, " ");
	if (parameters == NULL)
		return 1;
	strcpy(serialNumber, parameters);
	parameters = strtok(NULL, " ");
	if (parameters != NULL)
		return 1;
	
	return serviceDelete(Hangar, serialNumber);

}

int uiList(hangar *Hangar, char* parameters)
{
	char specialization[20], botString[200] = "";
	parameters = strtok(NULL, " ");
	if (parameters == NULL)
	{
		strcpy(botString,serviceListAll(Hangar));
		printf("%s",botString);
		return 0;
	}
	else
	{
		strcpy(specialization, parameters);
		parameters = strtok(NULL, " ");
		if (parameters != NULL)
			return 1;
		strcpy(botString, serviceListSpecial(Hangar, specialization));
		printf("%s", botString);
		return 0;

	}

}

void uiError()
{
	printf("Argo's AI adjutant:\n...Something caused an unexpected result...\n ...Try again...\n");
}

void run(hangar *Hangar)
{
	
	while (1)
	{
		int isError = 1;
		char command[50],action[10];
		char* parameters;

		printf("Argo's AI adjutant:\n ...Please input your command...\n");
		scanf(" %[^'\n']s", command);
		
		parameters = strtok(command, " ");
		strcpy(action, parameters);
		if (strcmp(action, "add") == 0)
			isError = uiAdd(Hangar, parameters);
		else if (strcmp(action, "update") == 0)
			isError = uiUpdate(Hangar, parameters);
		else if (strcmp(action, "delete") == 0)
			isError = uiDelte(Hangar, parameters);
		else if (strcmp(action, "list") == 0)
			isError = uiList(Hangar,parameters);
		else if (strcmp(action, "exit") == 0)
			return;
		if (isError == 1)
			uiError();
	}
}
int main()
{
	hangar *Hangar = (hangar*)malloc(sizeof(hangar));
	*Hangar = repoInit();
	run(Hangar);

	return  0;
}

