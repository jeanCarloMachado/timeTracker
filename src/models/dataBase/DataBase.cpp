#include "DataBase.h"

DataBase::DataBase()
{
	dataBase = NULL;
	char fileName[] = "/media/data/projetos/timeTracker/code/models/dataBase/dataBase.db";
	if(!open(fileName))
	{
		cout << "Não foi possível abrir o banco de dados" << endl;
		throw "Exception: Cannot open database ";
	}
}

DataBase::~DataBase()
{
}

bool DataBase::open(char* filename)
{
	if(sqlite3_open(filename,&dataBase) == SQLITE_OK)
		return true;
	
	return false;
}

vector<vector<string> > DataBase::query(char *query)
{
	sqlite3_stmt *statement;
	vector<vector<string> > results;

	if(sqlite3_prepare_v2(dataBase,query,-1,&statement,0) == SQLITE_OK)
	{
		int cols = sqlite3_column_count(statement);
		int result = 0;
		while(true)
		{
			result = sqlite3_step(statement);

			if(result == SQLITE_ROW)
			{
				vector<string> values;
				for(int col=0;col<cols;col++)
				{
					values.push_back((char*)sqlite3_column_text(statement,col));
				}
				results.push_back(values);
			}
			else
			{
				break;
			}
		}

		sqlite3_finalize(statement);
	}

	string error = sqlite3_errmsg(dataBase);
	if(error!="not an error") cout << query << " " << error << endl;

	return results;
}

void DataBase::close()
{
	sqlite3_close(dataBase);
}