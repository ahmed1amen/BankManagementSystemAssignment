#include "FileOps.h"
#include "Admin.h"
#include "Account.h"
#include "Employee.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;
bool FileOps::insertToDatabase(json o, string parentNode)
{
	json j = readDatabase();
	j[parentNode].push_back(o);
	writeDatabase(j);
	return true;
}
json FileOps::searchInDatabase(string parentNode, int id)
{
	json j = readDatabase();
	return j[parentNode][id];
}
bool FileOps::updateToDatabase(string parentNode, int id, json o)
{
	json j = readDatabase();
	j[parentNode][id] = o;
	writeDatabase(j);
	return true;
}
bool FileOps::deleteFromDatabase(string parentNode, int id)
{
	json j = readDatabase();
	j[parentNode].erase(id);
	writeDatabase(j);
	return true;
}
json FileOps::readDatabase()
{
	std::ifstream istream(FileOps::DATABASE);
	json j;
	istream >> j;
	istream.close();
	return j;
}
bool FileOps::writeDatabase(json j)
{
	std::ofstream ostream(FileOps::DATABASE);
	ostream << j;
	return true;
}