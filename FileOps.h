#pragma once
#include "Account.h"
#include "Employee.h"
class FileOps
{
public:
	void write_acc(Accounts, string, string, string, string, string, int, int, double);
	void write_emp(Employee, string, string, string, string, string, string, string, string, int, int, double);
};

