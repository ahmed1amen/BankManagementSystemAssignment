#include "Menu.h"
#include "Admin.h"
#include "Account.h"
#include "Employee.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

//menu for register user
void Accounts::user_menu(int user_sesstion)
{
	int ch;
	int amount = 0;
	Accounts acc;
	do {
		system("color A");
		cout << "Welcome Sir your account number is:  " << user_sesstion << endl;
		cout << "\n\t\t\t 1- Check Balance";
		cout << "\n\t\t\t 2- Withdrawal";
		cout << "\n\t\t\t 3- Deposit";
		cout << "\n\t\t\t 4- Transfer Fund";
		cout << "\n\t\t\t 5- View Transection";
		cout << "\n\t\t\t 0- Exit";
		cout << "\n\t\t\t Enter your Choice (0-5): ";

		if (cin >> ch)
		{
			switch (ch)
			{
			case 0:
				system("CLS");
				cout << "\n\n Account \n\n ";
				break;
			case 1:
				system("cls");
				acc.CurrentBalance(user_sesstion);
				break;
			case 2:
				cout << "\n\tEnter Amount to withdraw: ";
				cin >> amount;
				acc.deduct_Money(user_sesstion, amount);
				break;
			case 3:
				cout << "\n\tEnter Amount to Add: ";
				cin >> amount;
				acc.Deposit(user_sesstion, amount);
				acc.CurrentBalance(user_sesstion);
				break;
			case 4:
				system("cls");
				acc.transfareTO(user_sesstion);
				break;
			case 5:
				acc.viewTransfare(user_sesstion);
				break;
			default:
				cout << "\n\tWorng choise \n";
				break;
			}
		}
		else
		{
			cout << "\n\t Input only Digits please !";
			cin.clear();
			cin.ignore();
			ch = 10;
		}
	} while (ch != 0);

}

//menu for register user
void Employee::employee_menu(int user_sesstion)
{
	Accounts acc;
	int ch;
	int amount = 0;
	Employee e;
	do {
		system("color 9");
		cout << "\n\t\t\t 1- Create An Account";
		cout << "\n\t\t\t 2- View Info Of Account";
		cout << "\n\t\t\t 3- Show All Accounts";
		cout << "\n\t\t\t 4- Delete Account";
		cout << "\n\t\t\t 5- Close Account";
		cout << "\n\t\t\t 6- Update Your Details";
		cout << "\n\t\t\t 7- MiniStatement";
		cout << "\n\t\t\t 0- Exit";
		cout << "\n\t\t\t Enter your Choice (0-6): ";
		if (cin >> ch)
		{
			switch (ch)
			{
			case 0:
				system("CLS");
				cout << "\n\n Employees \n\n ";
				break;
			case 1:
				system("cls");
				acc.createAccount();
				break;
			case 2:
				system("cls");
				acc.searchDetails(user_sesstion);
				break;
			case 3:
				system("cls");
				acc.showDetails();
				break;
			case 4:
				acc.delete_details(user_sesstion);
				break;
			case 5:
				//acc.close_details(user_sesstion);
				break;
			case 6:
				system("cls");
				acc.update_details(user_sesstion);
				break;

			case 7:
				acc.ministatement(user_sesstion);
				break;
			default:
				cout << "\n\tWorng choise \n";
				break;
			}
		}
		else
		{
			cout << "\n\t Input only Digits please !";
			cin.clear();
			cin.ignore();
			ch = 10;
		}
	} while (ch != 0);
}

//menu for register Admin_menu
void Admin::Admin_menu(int user_sesstion)
{
	int ch;
	int amount = 0;
	Employee e;
	do {
		system("color E");
		cout << "\n\t\t\t 1- Create An Employee";
		cout << "\n\t\t\t 2- View Info Of Employee";
		cout << "\n\t\t\t 3- Show All Employee";
		cout << "\n\t\t\t 4- Delete Employee";
		cout << "\n\t\t\t 5- Update Your Details Of Employee";
		cout << "\n\t\t\t 0- Exit";
		cout << "\n\t\t\t Enter your Choice (0-6): ";

		if (cin >> ch)
		{
			switch (ch)
			{
			case 0:
				system("CLS");
				cout << "\n\n Admins \n\n ";
				Sleep(10);
				//return;
				break;
			case 1:
				system("cls");
				e.createEmployee();
				break;
			case 2:
				system("cls");
				e.search_Employee(user_sesstion);
				break;

			case 3:
				system("cls");
				e.show_Employees();
				break;

			case 4:
				e.delete_Employee(user_sesstion);
				break;
			case 5:
				system("cls");
				e.update_Employee(user_sesstion);
				break;

			default:
				cout << "\n\tWorng choise \n";
				break;
			}
		}
		else
		{
			cout << "\n\t Input only Digits please!";
			cin.clear();
			cin.ignore();
			ch = 10;
		}

	} while (ch != 0);
}

void Admin::login_Admin(int user, int pass)
{
	Employee e;
	int flag = 0;

	//getting data from file
	ifstream file_read("Employee_details.txt", ios::in);
	while (!file_read.eof())
	{
		/*file_read >> fname;
		file_read >> lname;
		file_read >> phone;
		file_read >> dob;
		file_read >> designation;
		file_read >> age;
		file_read >> ctc;
		file_read >> experience;
		file_read >> type;
		file_read >> employeeNumber;
		file_read >> passEmployee;
		file_read >> salary;*/
		if (file_read.eof())
		{
			break;
		}

		if (user == e.get_Id() && pass == e.get_pass())
		{
			cout << "\n Login sucessful...!" << endl;
			e.employee_menu(user);
			flag = 1;
		}

	}
	if (flag == 0)
	{
		cout << "\n Username & password Employee Not matched !" << endl;

	}
	file_read.close();
}