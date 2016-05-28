#include "Console.h"


Console::Console()
{
}


bool Console::activityManagement()
{
	Activity act;

	if(!strcmp(parameters[0],"insert"))
	{		
		act.insert(&parameters[2][0]);
	}
	else if(!strcmp(parameters[0],"remove"))
	{
		act.remove(&parameters[2][0]);
	}
	else if(!strcmp(parameters[0],"update"))
	{
		act.update(&parameters[2][0]);
	}
	else if(!strcmp(parameters[0],"show"))
	{
		act.show();
	}
	else if(!strcmp(parameters[0],"start"))
	{
		if(!act.startCounting(&parameters[2][0]))
			cout << "Passe o nome da atividade\n";
	}
	else if(!strcmp(parameters[0],"curr"))
	{
		act.viewCounting();
	}
	else if(!strcmp(parameters[0],"stop"))
	{
		act.stopCounting();
	}	
	return true;
	
}


bool Console::projectManagement()
{
	cout << "Console Controller" << endl;
	return true;
}

bool Console::goalManagement()
{
	cout << "Goal Controller" << endl;
	return true;
}

bool Console::reminderManagement()
{
	cout << "Reminder Controller" << endl;
	return true;
}

bool Console::initBuffers(char *sentence)
{
	while(*sentence)
	{
		*sentence = '\0';
		sentence++;
	}
	
	
	for(int i=0;i<PARAM_NUM;i++)
	{
		for(int e=0;e<PARAM_SIZE;e++)
		{
			parameters[i][e] = '\0';
		}
	}
	
	return true;
}

bool Console::runInterpreter()
{
	char sentence[SENTENC_SIZE];
	char *pSentence;
	char *currParm;
	

	while(true)
	{
		cout << "->";
		initBuffers(&sentence[0]);

		pSentence = &sentence[0];

		gets(sentence);			
		
		register int o = 0;
		register int u = 0;

		for(int i=0;i<SENTENC_SIZE;i++)
		{
			if(sentence[i]==' ')
			{
				o=0;
				u++;
			}
			else
			{
				parameters[u][o] = sentence[i];
				o++;
			}
		}
		
		if(!strcmp(parameters[1],"activity"))
		{
			activityManagement();
		}
		else if (!strcmp(parameters[1],"project"))
		{
			projectManagement();
		}
		else if (!strcmp(parameters[1],"goal"))
		{
			goalManagement();
		}
		else if (!strcmp(parameters[1],"reminder"))
		{
			reminderManagement();
		}
		else if (!strcmp(parameters[0],"clear"))
		{
			system(CLEAR);
		}
		else if(!strcmp(parameters[0],"exit"))
		{
			exit(0);
		}
		else 
		{
			cout << msg.show("notFound") << endl;
		}
	}

	return true;
}