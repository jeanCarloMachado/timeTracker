#include "Controller.h"

Controller::Controller()
{

}

string Controller::getName()
{
	return name;
}

bool Controller::setName(string _name)
{
	name = _name;
}