#include<iostream>
#include "Menu_Main.h"
#include <Windows.h>
#include "Employee.h"
using namespace std;
int main()

{
	

	Employee *emp = new Employee();

	emp->createEmployee();




	cout << "done ! ";

	/*
	Menu_Main m;
	m.menu();
	system("pause");
	system("clear");
	return 0;*/
}
