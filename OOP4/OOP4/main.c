#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
#include "main.h"
#include <crtdbg.h>
#include <ctype.h>

int uiAdd(operationArray* undo,operationArray* redo,hangar *Hangar, char* parameters)
{

	char serialNumber[20], state[20], specialization[20], energyCapacity[20];
	parameters = strtok(NULL, ", ");
	if (parameters == NULL)
		return 1;
	strcpy(serialNumber, parameters);
	parameters = strtok(NULL, ", ");
	if (parameters == NULL)
		return 1;
	strcpy(state, parameters);
	parameters = strtok(NULL, ", ");
	if (parameters == NULL)
		return 1;
	strcpy(specialization, parameters);
	parameters = strtok(NULL, ", ");
	if (parameters == NULL)
		return 1;
	strcpy(energyCapacity, parameters);
	parameters = strtok(NULL, ", ");
	if (parameters != NULL)
		return 1;

	return serviceAdd(undo, redo, Hangar, serialNumber, state, specialization, energyCapacity);

}

int uiUpdate(operationArray* undo, operationArray* redo, hangar *Hangar, char* parameters)
{
	char serialNumber[20], newState[20], newSpecialization[20], newEnergyCapacity[20];
	parameters = strtok(NULL, ", ");
	if (parameters == NULL)
		return 1;
	strcpy(serialNumber, parameters);
	parameters = strtok(NULL, ", ");
	if (parameters == NULL)
		return 1;
	strcpy(newState, parameters);
	parameters = strtok(NULL, ", ");
	if (parameters == NULL)
		return 1;
	strcpy(newSpecialization, parameters);
	parameters = strtok(NULL, ", ");
	if (parameters == NULL)
		return 1;
	strcpy(newEnergyCapacity, parameters);
	parameters = strtok(NULL, "");
	if (parameters != NULL)
		return 1;

	return serviceUpdate(undo, redo, Hangar, serialNumber, newState, newSpecialization, newEnergyCapacity);

}

int uiDelte(operationArray* undo, operationArray* redo, hangar *Hangar, char* parameters)
{
	char serialNumber[20];
	parameters = strtok(NULL, " ");
	if (parameters == NULL)
		return 1;
	strcpy(serialNumber, parameters);
	parameters = strtok(NULL, " ");
	if (parameters != NULL)
		return 1;

	return serviceDelete(undo, redo, Hangar, serialNumber);

}

int uiList(hangar *Hangar, char* parameters)
{
	char order[20], botString[200] = "";
	parameters = strtok(NULL, " ");
	if (parameters == NULL)
	{
		serviceListAll(Hangar, botString);
		printf("%s", botString);
		return 0;
	}
	else
	{
		int true = 0;
		strcpy(order, parameters);
		parameters = strtok(NULL, " ");
		if (parameters != NULL)
			return 1;

		for (int index = 0; index < strlen(order); index++)
			if (isdigit(order[index]) != 0)
				true = 1;

		
		if (true == 0)
			printBySpecialization(Hangar, botString, order);

		else
		{
			printByEnergy(Hangar, botString, order);
		}

		printf("%s", botString);
		return 0;
	}

}

int uiUndo(operationArray* undo, operationArray* redo, hangar *Hangar, char* checkNull)
{
	
	checkNull = strtok(NULL, " ");
	if (checkNull != NULL)
		return 1;

	return serviceUndo(undo, redo, Hangar);

}

int uiRedo(operationArray* undo, operationArray* redo, hangar *Hangar, char* checkNull)
{
	checkNull = strtok(NULL, " ");
	if (checkNull != NULL)
		return 1;

	return serviceRedo(undo, redo, Hangar);
}


void uiError()
{
	printf("Argo's AI adjutant:\n...Something caused an unexpected result...\n ...Try again...\n");
}

void run(operationArray* undo, operationArray* redo, hangar *Hangar)
{

	while (1)
	{
		int isError = 1;
		char command[50], action[10];
		char* parameters;

		printf("Argo's AI adjutant:\n ...Please input your command...\n");
		scanf(" %[^'\n']s", command);

		parameters = strtok(command, ", ");
		strcpy(action, parameters);
		if (strcmp(action, "add") == 0)
			isError = uiAdd(undo, redo, Hangar, parameters);
		else if (strcmp(action, "update") == 0)
			isError = uiUpdate(undo, redo, Hangar, parameters);
		else if (strcmp(action, "delete") == 0)
			isError = uiDelte(undo, redo, Hangar, parameters);
		else if (strcmp(action, "list") == 0)
			isError = uiList(Hangar, parameters);
		else if (strcmp(command, "undo") == 0)
			isError = uiUndo(undo, redo, Hangar, parameters);
		else if (strcmp(command, "redo") == 0)
			isError = uiRedo(undo, redo, Hangar, parameters);
		else if (strcmp(action, "exit") == 0) {
			//destroyOperationArray(undo);
			//destroyOperationArray(redo);
			//destroyHangar(Hangar);
			return;
		}
			
		if (isError == 1)
			uiError();
	}
}
int main()
{
	hangar *Hangar = (hangar*)malloc(sizeof(hangar));
	operationArray *undo = (operationArray*)malloc(sizeof(operationArray));
	operationArray *redo = (operationArray*)malloc(sizeof(operationArray));
	repoInit(Hangar);
	operationArrayInit(undo);
	operationArrayInit(redo);
	run(undo, redo, Hangar);
	_CrtDumpMemoryLeaks();
	return  0;
}




