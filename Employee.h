#pragma once
#include <iostream>
#include "Person.h"
class Employee :public Person
{
private:
	int salary;
	int designation;
	int age;
	int experience;
public:

	Employee()
	{
		designation = 0;
		age = 0;
		experience = 0;
		salary = 0.0;
	}
	/*~Accounts() {}*/
	void setDesignation(int);
	void setAge(int);
	void setExperience(int);
	void setSalary(double);

	int getDesignation();
	int getAge();
	int getExperience();
	double getSalary();

	void createEmployee(); 	//function for openning new Employee
	void search_Employee(int); //function to search details of perticular user
	void delete_Employee(int);	//function for deleting record_Employee
	void update_Employee(int);
	int get_last_index_Employee(); //Employee number automation 
	void number_system_put_Employee(int n1);
	void show_Employees(); //function for showing Employee details
	void employee_menu(int);
};

