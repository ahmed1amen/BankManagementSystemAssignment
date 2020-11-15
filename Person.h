#pragma once
#include <string>
using namespace std;
class Person
{
private:
	string f_name;
	string l_name;
	string phone;
	string data_of_birthday;
	int password;
	string type;
	int id;

public:

	Person()
	{
		f_name = "";
		l_name = "";
		phone = "";
		data_of_birthday = "";

		password = 0;
		id = 0;
	}
	void set_fname(string);
	void set_lname(string);
	void set_phone(string);
	void set_dataOfBirthday(string);
	void setType(string);
	void set_Pass(int);
	void set_Id(int);

	string get_fname();
	string get_lname();
	string get_phone();
	string get_dataOfBirthday();
	int get_pass();
	string getType();
	int get_Id();
	void copy_content(string a, string b); //global declaration
	void temp_file_clear();//for clearing temp file
	void clrscr();
};


