#include "Account.h"
#include "Person.h"
#include "Account.h"
#include <iostream>
#include <fstream>
#include<cctype>
#include<iomanip>
#include <Windows.h> 
#include<sstream>  
using namespace std;
//erson p;
Accounts acc;

void Accounts::setBalance(double s)
{
	balance = s;
}
double Accounts::getBalance() { return balance; }


void Accounts::createAccount()
{
	string fname;
	string lname;
	string phone;
	string data_of_birthday;
	string type;
	int password;
	int id;
	system("color 3");
	cout << "\n\tEnter your First name: ";
	cin >> fname;
	set_fname(fname);
	cin.clear();

	cout << "\n\tEnter Last name: ";
	cin >> lname;
	set_lname(lname);
	cin.clear();

	string temp_phone;
	cout << "\n\tEnter phone number: ";
	cin >> temp_phone;
	cin.clear();
	if (temp_phone.length() == 11)
	{
		phone = temp_phone;
		set_phone(phone);

	}
	else
	{
		while (temp_phone.length() != 11)
		{
			cout << "phone number must be 11 digit\n";
			cout << "\n input chone number: ";
			cin >> temp_phone;
			phone = temp_phone;
			set_phone(phone);
		}
	}

	cout << "\n\tEnter Birthday(01/01/1900): ";
	cin >> data_of_birthday;
	set_dataOfBirthday(data_of_birthday);
	cin.ignore();

	char atype = '\0';
	cout << "\n\tSelect Accounts Type(Savings s / Creating c): ";
	cin >> atype;
	if (tolower(atype) == 's')
	{
		type = "Saved";
		setType(type);
	}
	else if (tolower(atype) == 'c')
	{
		type = "Created";
		setType(type);
	}
	else
	{
		type = "Other";
		setType(type);
	}

	id = get_last_index();
	set_Id(id);
	cout << "\n\t Your Account Number: " << get_Id();

	cout << "\n\t Enter 4 digit account_pass: ";
	cin >> password;
	set_Pass(password);

	cout << "\n\t Enter Primary Balance: ";
	cin >> balance;
	setBalance(balance);

	/*ofstream file("account_details.txt", ios::out | ios::app);
	file << fname << " " << lname << " " << phone << " " << data_of_birthday 
		<< " " << type << " " << id << " " << password << " " << balance << endl;
	cout << endl;

	number_system_put(id);
	file.close();*/
}




int  Accounts::get_last_index() {
	ifstream infile("number.txt");
	string sLine;
	if (infile.good())
	{
		getline(infile, sLine);
		cout << sLine << endl;
	}
	infile.close();
	int last = std::stoi(sLine);
	return last++;
}

void  Accounts::number_system_put(int n1)
{
	n1 = n1 + 1;
	ofstream number_write("number.txt", ios::out);
	number_write << n1;
}
