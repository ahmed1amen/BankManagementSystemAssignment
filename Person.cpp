#include "Person.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


void Person::clrscr()
{
	cout << string(100, '\n');
}
void Person::set_fname(string fn)
{
	f_name = fn;
}
void Person::set_lname(string ln)
{
	f_name = ln;
}
void Person::set_phone(string ph)
{
	phone = ph;
}
void Person::set_dataOfBirthday(string dob)
{
	data_of_birthday = dob;
}
void Person::setType(string t)
{
	type = t;
}
void Person::set_Pass(int pass)
{
	password = pass;
}
void Person::set_Id(int idd)
{
	id = idd;
}

string Person::get_fname() { return f_name; }
string Person::get_lname() { return l_name; }
string Person::get_phone() { return phone; }
string Person::get_dataOfBirthday() { return data_of_birthday; }
int Person::get_pass() { return password; }
string Person::getType() { return type; }
int Person::get_Id() { return id; }

/*
copy content function for copy text to other file
*/
void Person::copy_content(string a, string b)
{
	char ch;
	int flag = 0;
	ifstream temp_read(a.c_str(), ios::in);
	ofstream file_write(b.c_str(), ios::out);
	while (!temp_read.eof())
	{
		temp_read.get(ch);
		file_write.put(ch);
		flag = 1;
	}
	if (flag != 1)
	{
		cout << "\n\tFile Error !";
	}

}

void  Person::temp_file_clear()
{
	char ch;
	int flag = 0;
	ofstream temp_write("temp.txt", ios::out);

	temp_write << " ";
	temp_write.close();
}
