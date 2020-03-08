#pragma once
#include "service.h"

class UI
{
private:
	Service controller;

public:
	UI(const Service& initController) : controller(initController){}
	void run();
	int makeAdmin(char* parameters);
	void uiError();
	int uiDelete(char * parameters);
	int uiUpdate(char * parameters);
	int uiList();
	int uiAdd(char* parameters);
	int uiNext();
	int uiSave(char * parameters);
	int uiMyList();
	int uiAssistantList(char * parameters);
	int readTheFile(char * parameters);
	int myListFile(char * parameters);
};