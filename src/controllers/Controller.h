#ifndef __CONTROLLER__
#define __CONTROLLER__

#include <iostream>
#include <string>

using namespace std;

class Controller
{
private:
	string name;

public:
	Controller();
	bool setName(string _name);
	string getName();
};

#endif