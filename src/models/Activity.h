#ifndef __ACTIVITY__
#define __ACTIVITY__

#include <iostream>
#include <cstdio>
#include <string>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <ctype.h>

#include "dataBase/DataBase.h"

using namespace std;

class Activity
{
public:
	static string name;
	static time_t start;
	static time_t end;
private: 
	string description;
	string projectName;
	int minutes;
	

public:
	Activity();
	bool insert(char *name);
	bool update(char *name);
	bool remove(char *name);
	bool show();

	//time functions
	bool startCounting(char *_name);
	bool viewCounting();
	bool stopCounting();
private:

};

#endif