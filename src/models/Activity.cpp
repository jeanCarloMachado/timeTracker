#include "Activity.h"


time_t Activity::start = 0;
time_t Activity::end = 0;
string Activity::name = "";

Activity::Activity()
{	
}

/* time methods */

bool Activity::startCounting(char *_name)
{

	if(!isalpha(*_name))
		return false;

	Activity::name = _name;

	Activity::start = time(NULL);
	cout << "Começando atividade." <<endl;

	return true;
}

bool Activity::stopCounting()
{
	
	time(&end);
	int seconds;
	seconds = int (difftime(Activity::end,Activity::start));
	printf("Finalizada atividade: %s \nTempo(s): %d \n",Activity::name.c_str(),seconds);

	minutes = (seconds/60);

	char query[100];
	sprintf(query,"UPDATE activities SET minutes=%i WHERE name='%s'",minutes,Activity::name.c_str());

	{
		DataBase *db;
		db = new DataBase;
		db->query(query);
		db->close();
	}
	Activity::name = "";

	return true;
}

bool Activity::viewCounting()
{
	Activity::end = time(NULL);
	int seconds;
	seconds = int(difftime(Activity::end,Activity::start));
	printf("Atividade: %s tempo(s): %i \n",Activity::name.c_str(),seconds);

	return true;	
}

/* manage methods */

bool Activity::insert(char *name)
{
	char tmp[50];
	strcpy(tmp,name);

	char description[100];
	cout << "Digite a descrição da atividade: ";
	gets(description); 

	char query[150];
	sprintf(query,"INSERT INTO activities(name,description,minutes) VALUES('%s','%s',0);",tmp,description);
	
	{
		DataBase *db;
		db = new DataBase;
		db->query(query);
		db->close();
	}

	return true;
}

bool Activity::update(char *_name)
{
	DataBase *db;
	db = new DataBase();
	char query[100];
	sprintf(query,"SELECT name,description FROM activities WHERE name='%s';",_name);
	vector<vector<string> > result = db->query(query);

	
	register int  i=0;
	for(vector<vector<string> >::iterator it = result.begin();it<result.end();++it)
	{
		vector<string> row = *it;
		Activity::name = row.at(0).c_str();
		description = row.at(1);
		//minutes = atoi(row.at(2));
	}

	char nName[50];
	char nDescription[100];

	cout << "Name [d]efault='" << name << "': ";
	gets(nName);
	cout << "Description [d]efault='" << description << "': ";
	gets(nDescription);
	

	if(!strcmp(nDescription,"") && !strcmp(nName,""))
	{
		db->close();
		return true;
	}

	sprintf(query,"UPDATE activities SET name='%s',description='%s' WHERE name='%s';",nName,nDescription,Activity::name.c_str());
	db->query(query);

	db->close();

	return true;
}

bool Activity::show()
{
	DataBase *db;
	db = new DataBase();
	char query[] = "SELECT name,description,minutes FROM activities;";
	vector<vector<string> > result = db->query(query);

	cout << "Nome-Descrição-Tempo(min)" << endl;
	
	register int  i=0;
	for(vector<vector<string> >::iterator it = result.begin();it<result.end();++it)
	{
		i++;
		vector<string> row = *it;

		
			cout << i << ": " << row.at(0) << "-" << row.at(1) << "-" << row.at(2) << endl;		
	}

	db->close();
	
	return true;
}

bool Activity::remove(char *name)
{
	char query[50];
	sprintf(query,"DELETE FROM activities WHERE name='%s'",name);

	{
		DataBase *db;
		db = new DataBase();
		db->query(query);
		db->close();
	}
	return true;
}

