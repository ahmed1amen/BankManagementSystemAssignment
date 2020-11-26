#include "Employee.h"
#include "Account.h"
#include "Person.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <sstream>  
#include "helper.cpp"
#include "nlohmann/json.hpp"
#include "FileOps.h"
using namespace std;
using json = nlohmann::json;
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

json Employee::getJson()
{

	json employee;


	employee["fullName"] = Employee::get_fname() + Employee::get_lname();
	employee["phone"] = Employee::get_phone();
	employee["dataOfBirthday"] = Employee::get_dataOfBirthday();
	employee["designation"] = Employee::getDesignation();
	employee["age"] = Employee::getAge();
	employee["experience"] = Employee::getExperience();
	employee["type"] = Employee::getType();
	employee["password"] = Employee::get_pass();
	employee["salary"] = Employee::getSalary();
	return employee;
}
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
	catch (exception e) {}
}

void Employee::number_system_put_Employee(int n1)
{
	n1 = n1 + 1;
	ofstream number_write("number_Employee.txt", ios::out);
	number_write << n1;
}



void Employee::createEmployee()
{

	//	std::ifstream i("file.json");

	//json j = {
	//	{
	//"employees" ,
	//	{

	//  {"ID", 12},
	//  {"Username", "ahmed1amen"},
	//  {"Password", "'1pi23up9eas7dyh238o4u8qwer12@#$%@!@#"},
	//  {"Full Name", "Ahmed Amen Ramadan"},
	//  {"Phone", "01066104107"},
	//  {"Date Of Birth", "16-12-1997"},
	//  {"Type", "Saving"},
	//  {"Salary", 1000.550}
	//  },

	//	}



	//};


	//std::ofstream o("database.json");
	//o << std::setw(4) << j << std::endl;

	/*json child = {

	  {"ID", 12},
	  {"Username", "a brand new Object"},
	  {"Password", "a brand new Object"},
	  {"Full Name", "a brand new Object"},
	  {"Phone", "a brand new Object"},
	  {"Date Of Birth", "a brand new Object"},
	  {"Type", "a brand new Object"},
	  {"Salary", 9999999999}

		};


	std::ifstream i("database.json");
	json j;
	i >> j;

	j["employees"][0].clear();
	j["employees"].push_back(child);
	for (json o : j["employees"]) {
	std::cout << o["Date Of Birth"] << '\n';
	std::cout << o["Password"] << '\n';
	std::cout << o["Phone"] << '\n';
	std::cout << o["Salary"] << '\n';




		json jss =  fop->searchInDatabase("employees", 1212);
	if (jss.is_null())
		std::cout << "Employee" << " Not Found !! ";

		.



		// Update 

		json employeeJosnObject = fop->searchInDatabase("employees", 0);   //Find And Get The Object 
	   employeeJosnObject["password"] = "1234";  // Update Object Data
      fop->updateToDatabase(0, employeeJosnObject, "employees");  // Save Object To The Database

	}*/

	


	Employee* employee = new Employee();


	system("color C");

	cout << "\n\tEnter first name: ";
	employee->set_fname(Helper::readString(cin));

	cout << "\n\tEnter Last name: ";
	employee->set_lname(Helper::readString(cin));

	cout << "\n\tEnter phone number: ";
	employee->set_phone(Helper::readString(cin,true,11));

	cout << "\n\tEnter Birthday(DD/MM/YYYY): ";
	employee->set_dataOfBirthday(Helper::readString(cin));
	
	cout << "\n\tEnter Designation: ";
	employee->setDesignation(Helper::readInt(cin));

	cout << "\n\tEnter Employee Age: ";
	employee->setAge(Helper::readInt(cin));

	cout << "\n\tEnter Employee Experience: ";
	employee->setExperience(Helper::readInt(cin));

	cout << "\n\tSelect Accounts Type(Savings s / Creating c): ";
	char atype = Helper::readChar(cin);
	
	if (tolower(atype) == 'c')
		employee->setType("Created");
	else
		employee->setType("Savings");
	cout << "\n\tEnter password (min 4 digit): ";
	set_Pass(Helper::readInt(cin));

	cout << "\n\t Enter Primary salary: ";
	setSalary(Helper::readDouble(cin));


	
	fop->insertToDatabase(employee->getJson(), "employees");




	cout << "\n Employee Account Created";
}