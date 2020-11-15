#include "Employee.h"
#include "Account.h"
#include "Person.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <sstream>  
using namespace std;
Employee e;
void Employee::setSalary(double s)
{
	salary = s;
}
void Employee::setDesignation(int des)
{
	designation = des;
}
void Employee::setAge(int ag)
{
	age = ag;
}
void Employee::setExperience(int exp)
{
	experience = exp;
}

int Employee::getDesignation() { return designation; }
int Employee::getAge() { return  age; }
int Employee::getExperience() { return  experience; }
double Employee::getSalary() { return salary; }

int Employee::get_last_index_Employee() 
{
	ifstream infile("number_Employee.txt");
	string sLine;
	if (infile.good())
	{
		getline(infile, sLine);
		cout << sLine << endl;
	}
	infile.close();
	try {
		int last = stoi(sLine);
		return last++;
	}
	catch (exception e){}
}

void Employee::number_system_put_Employee(int n1)
{
	n1 = n1 + 1;
	ofstream number_write("number_Employee.txt", ios::out);
	number_write << n1;
}
void Employee::createEmployee()
{
	string fname;
	string lname;
	string phone;
	string data_of_birthday;
	string type;
	int password;
	system("color C");


	cout << "\n\tEnter first name: ";
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

	cout << "\n\tEnter Designation: ";
	cin >> designation;
	setDesignation(designation);
	cin.clear();

	cout << "\n\tEnter Employee Age: ";
	cin >> age;
	setAge(age);
	cin.clear();

	cout << "\n\tEnter Employee Experience: ";
	cin >> experience;
	setExperience(experience);
	cin.clear();

	char atype = '\0';
	cout << "\n\tSelect Accounts Type(Savings s / Creating c): ";
	cin >> atype;
	if (tolower(atype) == 's')
	{
		type = "Saved";
		setType(type);
	}
	else
	{
		type = "Created";
		setType(type);
	}

	int id = get_last_index_Employee();
	set_Id(id);
	cout << "\n\tYour Accounts Number: " << get_Id();
	cout << "\n\tEnter password (min 4 digit): ";
	cin >> password;
	set_Pass(password);

	cout << "\n\t Enter Primary salary: ";
	cin >> salary;
	setSalary(salary);
	
	/*ofstream file("Employee_details.txt", ios::out | ios::app);
	file << fname << " " << lname << " " << phone << " " << data_of_birthday << " " << designation << " "
		<< age << " " << experience << " " << type << " " << id << " "
		<< password << " " << salary << endl;
	cout << endl;
	number_system_put_Employee(id);
	file.close();*/

	cout << "\n Employee Account Created";
}