#ifdef __WINDOWS__
	#define CLEAR "cls"
	#include <windows.h>
#else
	#define CLEAR "clear"
	#include <unistd.h>
#endif

#include <iostream>
#include <cstdlib>
#include "views/Console.h"
#include "views/helpers/Message.h"

using namespace std;

int main(int argc, char *argv[])
{
	Message msg;

	system(CLEAR);

	if(argc!=2)
	{
		cout << msg.show("errorParam") << endl;
		return 0;
	}
	cout << msg.show("hello") << endl;
	usleep(1000000*1);
	system(CLEAR);
	//Se term for chamado será inicializado o terminal
	if(*argv[1]=='c')
	{
		Console cn;
		cn.runInterpreter();
	}
	else
	{	
		//initialize GUI
		return 0;
	}
	return 1;
}
