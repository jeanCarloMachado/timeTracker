#ifndef __MESSAGE__
#define __MESSAGE__

#include <iostream>
#include <string>

using namespace std;

class Message
{

private:
	string id;

public:
	Message();
	string show(string);
};

#endif