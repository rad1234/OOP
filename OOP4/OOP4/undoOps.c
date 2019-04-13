#include "Repo.h"
#include <stdlib.h>

void operationArrayInit(operationArray* operations)
{
	operations->capacity = 1;
	operations->size = 0;
	operations->operations = (operation*)malloc(operations->capacity * sizeof(operation));

}

void resizeOperations(operationArray* operations)
{
	operations->capacity *= 2;
	operations->operations = (operation*)realloc(operations->operations, operations->capacity * sizeof(operation));

}

operation operationInit(void(*operationPointer)(hangar*, repairBot), repairBot bot)
{
	operation operation;
	operation.operationPointer = operationPointer;
	operation.repairBot = bot;
	return operation;
}

operation inverseOperationInit(void(*operationPointer)(hangar*, repairBot), repairBot bot)
{
	operation operation;

	if (operationPointer == repoAdd)
		operation.operationPointer = repoDelete;
	else if (operationPointer == repoUpdate)
		operation.operationPointer = repoUpdate;
	else if (operationPointer == repoDelete)
		operation.operationPointer = repoAdd;
	

	operation.repairBot = bot;
	return operation;
}

void removeOperation(operationArray* operations)
{
	operations->size--;
	destroyBot(&operations->operations[operations->size].repairBot);
}

void addOperation(operationArray* operationsToUndo, operation operation)
{
	operationsToUndo->operations[operationsToUndo->size] = operation;
	operationsToUndo->size++;

	if (operationsToUndo->size == operationsToUndo->capacity)
		resizeOperations(operationsToUndo);

}

void destroyOperationArray(operationArray* operations)
{
	for (int index = 0; index < operations->size; index++)
		destroyBot(&operations->operations[index].repairBot);

	free(operations->operations);
	free(operations);
}

