#include "Menu_Main.h"
#include<iostream>
#include "Account.h"
#include "Employee.h"
#include "Admin.h"
#include "Encrypt.h"
#include "Welcome.h"
#include<conio.h>
#include<iomanip>
#include<string>
#include <Windows.h>
using namespace std;
int user_admin; // login_Admin_menu (global Variable)
void Menu_Main::menu()
{
	int ch;
	int login_state = 0;
	int user;
	int pass;
	string str;
	Accounts a;
	Employee e;
	Admin ad;
	Welcome w;
	Encrypt enc;
	do {
		w.intro();
		cout << "\n\t\t\t\t\t\t***************************************************"
			<< "\n\t\t\t\t\t\t*                                                 *"
			<< "\n\t\t\t\t\t\t*              1- Login To your Account.	  *"
			<< "\n\t\t\t\t\t\t*              2- Employee			  *"
			<< "\n\t\t\t\t\t\t*              3- Admin.                          *"
			<< "\n\t\t\t\t\t\t*              0- Exit.                           *"
			<< "\n\t\t\t\t\t\t*                                                 *"
			<< "\n\t\t\t\t\t\t***************************************************\n";
		cout << "\n\n\t\t\t\t\t\tEnter your choice: ";
		if (cin >> ch)
		{
			switch (ch)
			{
			case 1:
				cout << "\n\t Enter Account Number:  ";
				cin >> user;
				cout << "\n\t Enter 4-digit passcode: ";
				cin >> pass;
				system("cls");
				a.login_user(user, pass);
				break;
			case 2:
				cout << "\n\t Enter Account Number: ";
				cin >> user;
				cout << "\n\t Enter 4-digit password: ";
				cin >> pass;
				system("cls");
				ad.login_Admin(user, pass);
				break;
			case 3:
				cout << "\n\t Enter 4-digit User Admin: ";
				cin >> user_admin;
				system("cls");
				ad.login_Admin_menu(user_admin);
				break;
			case 4:
				system("cls");
				enc.f_encryp(str);
				break;

			}
		}
		else
		{
			cout << "\n\t Input only Digits please ! Press Enter To continue";
			cin.clear();
			cin.ignore();
			ch = 10;
		}



	} while (ch != 0);
}