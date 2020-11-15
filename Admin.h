#pragma once
#include "Employee.h"
#include<string>
using namespace std;
class Admin :public Employee
{
private:
public:
	void Admin_menu(int);
	void login_Admin(int, int);	//login_Admin function
	void login_Admin_menu(int);	//login_Admin_menu function
};



