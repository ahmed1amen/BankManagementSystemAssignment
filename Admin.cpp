#include "Admin.h"
#include "Employee.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;


void Admin::login_Admin_menu(int user_admin)
{
	Admin ad;
	int flag = 0;

	if (user_admin == 0000)
	{
		cout << "\n Login sucessful !" << endl;
		ad.Admin_menu(user_admin);
		flag = 1;
	}

	if (flag == 0)
	{
		cout << "\n password Admin Not matched !" << endl;

	}

}	
