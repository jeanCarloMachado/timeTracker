#ifndef __ACTIVITYCONTROLLER__
#define __ACTIVITYCONTROLLER__

#include <iostream>
#include <string>

#include "Controller.h"
#include "../models/Activity.h"

using namespace std;

class ActivityController : public Controller
{

private:
	Activity act;

public:
	ActivityController();

	/*console actions */
	bool insert(char *_name);
	bool remove(char *_name);
	bool update(char *_name);
	bool show();
	bool startCounting(char *_name);
	bool viewCounting();
	bool stopCounting();
};

#endif