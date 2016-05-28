#ifndef __CONSOLE__
#define __CONSOLE__

#ifdef __WINDOWS__
	#define CLEAR "cls"
#else
	#define CLEAR "clear"
#endif

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstring>
#include <cstdio>


#include "helpers/Message.h"
#include "../controllers/ActivityController.h"

#define PARAM_NUM 5
#define PARAM_SIZE 20
#define SENTENC_SIZE 80

using namespace std;

class Console
{
// atributtes
public:
	char parameters[PARAM_NUM][PARAM_SIZE];
	Message msg;
private:
	
	//ActivityController act;
// méthods
public:
	Console();
	bool runInterpreter();

private:
	void quit(int log);

	bool activityManagement();
	bool projectManagement();
	bool goalManagement();
	bool reminderManagement();
	bool initBuffers(char *);


	
};

#endif
