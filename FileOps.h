#pragma once
#include "Account.h"
#include "Employee.h"
#include "nlohmann/json.hpp"
using json = nlohmann::json;
class FileOps
{
public:


	const string DATABASE="database.json";
	void write_acc(Accounts, string, string, string, string, string, int, int, double);
	void saveEmployee(Employee);


	json readDatabase();
	bool writeDatabase(json j);

	bool insertToDatabase(json o, string parentNode);
	json searchInDatabase( string parentNode, int id);
	bool updateToDatabase(string parentNode , int id,json o);
	bool deleteFromDatabase(string parentNode,  int id );




};

