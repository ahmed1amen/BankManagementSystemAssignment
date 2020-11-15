#include "FileOps.h"
#include "Admin.h"
#include "Account.h"
#include "Employee.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

void Accounts::login_user(int user, int pass)
{
	Accounts acc;
	int flag = 0;
	//getting data from file
	ifstream file_read("account_details.txt", ios::in);
	while (!file_read.eof())
	{
		if (file_read.eof())
		{
			break;
		}
		if (user == get_Id() && pass == get_pass())
		{
			cout << "\n Login sucessful..!" << endl;
			user_menu(user);
			flag = 1;
		}
	}
	if (flag == 0)
	{
		cout << "\n User name & acc.get_pass() Not matched!" << endl;

	}
	file_read.close();
}
void FileOps::write_acc(Accounts acc, string fname, string lname,
	string phone, string data_of_birthday, string type, int id , int password ,double balance)
{
	ofstream file("account_details.txt", ios::out | ios::app);
	//
	acc.createAccount();
	file <<fname<< " " << lname << " " << phone << " " << data_of_birthday
		<< " " << type << " " << id << " " << password << " " << balance << endl;
	cout << endl;

	acc.number_system_put(id);
	file.close();
}

void Accounts::searchDetails(int user_no) //user_no for user session for only specified user can show
{
	Accounts acc;
	int flag = 0;
	Accounts();//constructor call to empty variables;
	ifstream file_read("account_details.txt", ios::in);
	system("color 5");
	cout << "\n\tEnter Accounts number: ";
	cin >> user_no;
	//cin.clear();

	while (file_read)
	{

		/*file_read >> fname;
		file_read >> lname;
		file_read >> phone;
		file_read >> dob;
		file_read >> type;
		file_read >> accountNumber;
		file_read >> account_pass;
		file_read >> balance;
		file_read >> close;*/

		if (file_read.eof())
		{
			break;
		}

		if (user_no == get_Id())
		{
			cout << "\n\tAccounts Number is :" << get_Id();
			cout << "\n\tName               :" << get_fname() << " " << get_lname();
			cout << "\n\tPhone              :" << get_phone();
			cout << "\n\tDate of birth      :" << get_dataOfBirthday();
			cout << "\n\tAccounts Type      :" << getType();
			cout << "\n\tBalance            :" << getBalance() << " $";
			//cout << "\n\tAccount Status     :" << close;
			cout << "\n\n\n";
			flag = 1;
		}


	}
	if (flag != 1)
	{
		cout << "\n\tNo record found";

	}
	file_read.close();

}

void Accounts::delete_details(int user_no)
{
	Accounts acc;
	char buff;
	int flag = 0;
	string a = "account_details.txt";
	string b = "temp.txt";

	Accounts();//constructor call to empty variables;
	ifstream file_read("account_details.txt", ios::in);
	ofstream file_temp("temp.txt", ios::out | ios::app);
	system("color 4");
	cout << "\n\tEnter Accounts number: ";
	cin >> user_no;
	//cin.clear();

	while (!file_read.eof())
	{
		/*file_read >> fname;
		file_read >> lname;
		file_read >> phone;
		file_read >> dob;
		file_read >> type;
		file_read >> accountNumber;
		file_read >> account_pass;
		file_read >> balance;
		file_read >> close;*/

		if (file_read.eof())
		{
			break;
		}
		if (user_no == acc.get_Id())
		{
			cout << acc.get_fname() << " " << acc.get_lname() << " " << acc.get_phone() << " " << acc.get_dataOfBirthday() << " " << acc.getType()
				<< " " << acc.get_Id() << " " << acc.get_pass() << " " << balance << endl;
			flag = 1;
		}
		else
		{
			file_temp << acc.get_fname() << " " << acc.get_lname() << " " << acc.get_phone() << " " << acc.get_dataOfBirthday() << " " << acc.getType()
				<< " " << acc.get_Id() << " " << acc.get_pass() << " " << balance << endl;
		}
	}
	if (flag != 1)
	{
		cout << "\n\tNo record found";

	}
	file_temp.close();
	file_read.close();
	copy_content(b, a);

	cout << "\n\tAccounts Is Removed!\n";
	temp_file_clear();
}

/*
void Accounts::close_details(int user_no)
{
	int ch;
	char buff;
	int flag = 0;
	string a = "account_details.txt";
	string b = "temp.txt";

	Accounts();//constructor call to empty variables;
	ifstream file_read("account_details.txt", ios::in);
	ofstream file_temp("temp.txt", ios::out | ios::app);
	system("color 2");
	cout << "\n\tEnter Account number: ";
	cin >> user_no;
	//cin.clear();
	while (!file_read.eof())
	{

		/*file_read >> fname;
		file_read >> lname;
		file_read >> phone;
		file_read >> dob;
		file_read >> type;
		file_read >> accountNumber;
		file_read >> account_pass;
		file_read >> balance;
		file_read >> close;

		if (file_read.eof())
		{
			break;
		}

		if (user_no == acc.get_Id())
		{
			cout << "\n\tAccount Number is: " << acc.get_Id();
			cout << "\n\tFill up Details with new records: \n";

			cout << "\n\n\t New Status: ";
			cin >> close;
			cin.clear();


			cout << "\n\t Current Account Type:" << type;
			cout << "\n\t Change Type (Saving s /Other o) otherwiese press (N) :";
			char ans;
			cin >> ans;
			cin.clear();
			if (tolower(ans) == 'n')
			{
				cout << "\n\tOk !account type is not chenged !\n ";
			}
			else if (tolower(ans) == 's')
			{
				type = "Saving";
			}
			else
			{
				type = "Other";
			}
			file_temp << acc.get_fname() << " " << acc.get_lname() << " " << acc.get_phone() << " " << acc.get_dataOfBirthday() << " " << acc.getType()
				<< " " << acc.get_Id() << " " << acc.get_pass() << " " << balance << endl;
			flag = 1;
		}
		else
		{
			file_temp << acc.get_fname() << " " << acc.get_lname() << " " << acc.get_phone() << " " << acc.get_dataOfBirthday() << " " << acc.getType()
				<< " " << acc.get_Id() << " " << acc.get_pass() << " " << balance << endl;
		}

	}
	if (flag != 1)
	{
		cout << "\n\tNo record found";

	}
	file_temp.close();
	file_read.close();
	copy_content(b, a);

	cout << "\n\t Done ! Details Updated THank You.\n";
	temp_file_clear();

}
*/
/* End View All Transection */
void Accounts::update_details(int user_no)
{
	Accounts acc;
	string fname;
	string lname;
	string phone;
	string data_of_birthday;
	string type;

	int flag = 0;
	string a = "account_details.txt";
	string b = "temp.txt";

	Accounts();//constructor call to empty variables;
	ifstream file_read("account_details.txt", ios::in);
	ofstream file_temp("temp.txt", ios::out | ios::app);
	system("color 2");
	cout << "\n\tEnter Account number: ";
	cin >> user_no;
	//cin.clear();
	while (!file_read.eof())
	{

		/*file_read >> fname;
		file_read >> lname;
		file_read >> phone;
		file_read >> dob;
		file_read >> type;
		file_read >> accountNumber;
		file_read >> account_pass;
		file_read >> balance;
		file_read >> close;*/

		if (file_read.eof())
		{
			break;
		}

		if (user_no == acc.get_Id())
		{
			cout << "\n\tAccount Number is: " << acc.get_Id();
			cout << "\n\tFill up Details with new records: \n";

			cout << "\n\n\t New First name: ";

			cin >> fname;
			set_fname(fname);
			cin.clear();

			cout << "\n\t New Last name: ";
			cin >> lname;
			set_lname(lname);
			cin.clear();

			cout << "\n\t New  phone: ";
			cin >> phone;
			set_phone(phone);
			cin.clear();

			cout << "\n\t New Dob: ";
			cin >> data_of_birthday;
			set_dataOfBirthday(data_of_birthday);
			cin.clear();

			cout << "\n\t Current Account Type:" << type;
			cout << "\n\t Change Type (Saving S/Other O) otherwiese press (N) :";
			char ans;
			cin >> ans;
			cin.clear();
			if (tolower(ans) == 'n')
			{
				cout << "\n\tOk !account type is not chenged !\n ";
			}
			else if (tolower(ans) == 's')
			{
				type = "Saving";
				setType(type);
			}
			else
			{
				type = "Other";
				setType(type);
			}
			file_temp << fname << " " << lname << " " << phone << " " << data_of_birthday << " "
				<< type << " " << acc.get_Id() << " " << acc.get_pass() << " " << balance << endl;
			/*file_temp << acc.get_fname() << " " << acc.get_lname() << " " << acc.get_phone() << " " << acc.get_dataOfBirthday() << " " << acc.getType()
				<< " " << acc.get_Id() << " " << acc.get_pass() << " " << balance << endl;*/
			flag = 1;
		}
		else
		{
			file_temp << acc.get_fname() << " " << acc.get_lname() << " " << acc.get_phone() << " " << acc.get_dataOfBirthday() << " " << acc.getType()
				<< " " << acc.get_Id() << " " << acc.get_pass() << " " << getBalance() << endl;
		}
	}
	if (flag != 1)
	{
		cout << "\n\tNo record found";

	}
	file_temp.close();
	file_read.close();
	copy_content(b, a);

	cout << "\n\t Done ! Details Updated THank You.\n";
	temp_file_clear();
}

/*Start entmini statem function */
void Accounts::ministatement(int user_no)
{
	Accounts acc;
	int number, amount, flag = 0, pbalance = 0;
	string status;
	Accounts();//constructor call to empty variables;
	ifstream file_read("account_details.txt", ios::in);

	while (file_read)
	{
		/*file_read >> fname;
		file_read >> lname;
		file_read >> phone;
		file_read >> dob;
		file_read >> type;
		file_read >> accountNumber;
		file_read >> account_pass;
		file_read >> balance;
		file_read >> close;*/

		if (file_read.eof())
		{
			break;
		}

		if (user_no == acc.get_Id())
		{
			pbalance = balance;
		}
	}

	file_read.close();
	//transection part
	system("color B");
	cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "\n\tAccounts Number : " << acc.get_Id() << endl;
	cout << "\n\n";

	ifstream tr_file_read("transec.txt", ios::in);
	//cin.clear();
	cout << "\n\t" << "Date"
		<< " | " << "Amount" << " | " << "CR / DR " << endl;

	while (tr_file_read)
	{
		tr_file_read >> number;
		tr_file_read >> amount;
		tr_file_read >> status;
		if (tr_file_read.eof())
		{
			break;
		}

		if (user_no == number)
		{
			cout << "\t" << " | " << amount << " | " << status << " | " << endl;
			flag = 1;
		}


	}
	if (flag != 1)
	{
		cout << "\n\tNo record found";
	}
	cout << "\n\n";
	cout << "Total Primary Balance :" << pbalance << "/." << endl;
	tr_file_read.close();

}


/*End mini statement function */
void Accounts::showDetails()
{
	int count = 1;
	//Accounts e;
	//ifstream inFile;
	ifstream file_read("account_details.txt", ios::in);

	if (!file_read)

	{
		system("color C");
		cout << "File could not be open !! Press any Key...";

		return;

	}
	system("color C");
	cout << "\n\n\t\tACCOUNTS LIST\n\n";

	cout << "===============================================================================================\n";

	cout << "Name" << "		" << "Phone" << "		" << "Data Birthday" << "	" << "Type" << "	" << "Account No." << "  " << "Password" << "  " << "Balance" << " " << "Status" << endl;

	cout << "===============================================================================================\n";
	string word;
	while (file_read >> word)
	{
		cout << word << "	";
		if (count >= 9)
		{
			cout << endl;
			count = 0;
		}
		count++;
		/*file_read >> fname;
		file_read >> lname;
		file_read >> phone;
		file_read >> dob;
		file_read >> type;
		file_read >> accountNumber;
		file_read >> account_pass;
		file_read >> balance;*/

		/*if (file_read.eof() != NULL)
		{
			cout << fname << " " << lname << "\t" << phone << "\t"
			<< dob << "\t" << type << "\t" << accountNumber << "\t" << account_pass << "\t" << balance << endl;

			system("pause");
		}*/
	}
	/*if (flag != 1)
	{
		cout << "\n\tNo record found";
	}*/
	file_read.close();
	cout << "\n\n\n";
}
void Accounts::CurrentBalance(int user_no)
{
	Accounts acc;
	Accounts();//constructor call to empty variables;
	ifstream file_read("account_details.txt", ios::in);
	while (file_read)
	{

		/*file_read >> acc.get_f_name();
		file_read >> acc.get_lname();
		file_read >> acc.get_phone();
		file_read >> acc.get_dataOfBirthday();
		file_read >> acc.getType();
		file_read >> acc.get_Id();
		file_read >> acc.get_pass();
		file_read >> balance;*/

		if (file_read.eof())
		{
			break;
		}
		if (user_no == acc.get_Id())
		{
			system("color C");
			cout << "\n\tCurrent Balance: " << balance << " Egy.";
			cout << "\n\n\n";
		}
	}
	file_read.close();
}

/*start operator overloading (treanfering amount)*/
void Accounts::Deposit(int user_no, int amt)
{
	Accounts acc;
	string a = "account_details.txt";
	string b = "temp.txt";

	Accounts();//constructor call to empty variables;
	ifstream file_read("account_details.txt", ios::in);
	ofstream file_temp("temp.txt", ios::out | ios::app);
	ofstream tr_write("transec.txt", ios::out | ios::app);
	while (!file_read.eof())
	{

		/*file_read >> acc.get_f_name();
		file_read >> acc.get_lname();
		file_read >> acc.get_phone();
		file_read >> acc.get_dataOfBirthday();
		file_read >> acc.getType();
		file_read >> acc.get_Id();
		file_read >> acc.get_pass();
		file_read >> balance;*/

		if (file_read.eof())
		{
			break;
		}
		if (user_no == acc.get_Id())
		{
			balance = balance + amt;

			file_temp << acc.get_fname() << " " << acc.get_lname() << " " << acc.get_phone() << " " << acc.get_dataOfBirthday() << " " << acc.getType()
				<< " " << acc.get_Id() << " " << acc.get_pass() << " " << balance << endl;

			tr_write << acc.get_Id() << " " << " " << amt << " " << "CR" << endl;
		}
		else
		{
			file_temp << acc.get_fname() << " " << acc.get_lname() << " " << acc.get_phone() << " " << acc.get_dataOfBirthday() << " " << acc.getType()
				<< " " << acc.get_Id() << " " << acc.get_pass() << " " << balance << endl;
		}
	}

	file_temp.close();
	file_read.close();
	copy_content(b, a);
	cout << "\n\t Done ! Amount Added\n";
	temp_file_clear();
}
void Accounts::deduct_Money(int user_no, int amt)
{
	Accounts acc;
	string a = "account_details.txt";
	string b = "temp.txt";
	char tr_date[9];

	int flag = 0;
	Accounts();//constructor call to empty variables;
	ifstream file_read("account_details.txt", ios::in);
	ofstream file_temp("temp.txt", ios::out | ios::app);
	ofstream tr_write("transec.txt", ios::out | ios::app);
	while (!file_read.eof())
	{
		/*file_read >> acc.get_fname();
		file_read >> acc.get_lname();
		file_read >> acc.get_phone();
		file_read >> acc.get_dataOfBirthday();
		file_read >> acc.getType();
		file_read >> acc.get_Id();
		file_read >> acc.get_pass();
		file_read >> balance;*/

		if (file_read.eof())
		{
			break;
		}

		if (user_no == acc.get_Id())
		{
			if (balance != 0 && balance > amt)
			{
				balance = balance - amt;

				file_temp << acc.get_fname() << " " << acc.get_lname() << " " << acc.get_phone() << " " << acc.get_dataOfBirthday() << " " << acc.getType()
					<< " " << acc.get_Id() << " " << acc.get_pass() << " " << balance << endl;

				tr_write << acc.get_Id() << " " << amt << " " << "DR" << endl;

				flag = 1;
			}
			else
			{

				cout << "\nYour transection can not be completed balance is Zero or Less than withdrawal amount\n! ";
				file_temp << acc.get_fname() << " " << acc.get_lname() << " " << acc.get_phone() << " " << acc.get_dataOfBirthday() << " " << acc.getType()
					<< " " << acc.get_Id() << " " << acc.get_pass() << " " << balance << endl;
			}
		}

		else
		{
			file_temp << acc.get_fname() << " " << acc.get_lname() << " " << acc.get_phone() << " " << acc.get_dataOfBirthday() << " " << acc.getType()
				<< " " << acc.get_Id() << " " << acc.get_pass() << " " << balance << endl;
		}

	}

	file_temp.close();
	file_read.close();
	copy_content(b, a);
	if (flag == 1)
	{
		cout << "\n\t Done ! Amount Deducted\n";

	}

	temp_file_clear();
}
/*end operator overload*/

/*Start Fund transfer function */
void Accounts::transfareTO(int user_no)
{
	Accounts acc;
	int user2_no, amt = 0, flag = 0;
	char ans;
	system("color 1");
	cout << "\nEnter Account Transfer Number: ";
	cin >> user2_no;

	cout << "\nEnter Amount : ";
	cin >> amt;

	string a = "account_details.txt";
	string b = "temp.txt";

	Accounts();//constructor call to empty variables;
	ifstream file_read("account_details.txt", ios::in);
	ofstream file_temp("temp.txt", ios::out | ios::app);
	ofstream tr_write("transec.txt", ios::out | ios::app);
	while (!file_read.eof())
	{

		/*file_read >> acc.get_fname();
		file_read >> acc.get_lname();
		file_read >> acc.get_phone();
		file_read >> acc.get_dataOfBirthday();
		file_read >> acc.getType();
		file_read >> acc.get_Id();
		file_read >> acc.get_pass();
		file_read >> balance;*/

		if (file_read.eof())
		{
			break;
		}

		if (user2_no == acc.get_Id())
		{
			cout << "\nAccount Holder's name: " << acc.get_fname() << " " << acc.get_lname() << endl;
			cout << "enter(y/n): ";
			cin >> ans;

			if (ans == 'n')
			{
				flag = 1;
				break;
			}

			balance = balance + amt;

			file_temp << acc.get_fname() << " " << acc.get_lname() << " " << acc.get_phone() << " " << acc.get_dataOfBirthday() << " " << acc.getType()
				<< " " << acc.get_Id() << " " << acc.get_pass() << " " << balance << endl;

			tr_write << acc.get_Id() << "  " << amt << " " << "CR" << endl;

		}
		else
		{
			file_temp << acc.get_fname() << " " << acc.get_lname() << " " << acc.get_phone() << " " << acc.get_dataOfBirthday() << " " << acc.getType()
				<< " " << acc.get_Id() << " " << acc.get_pass() << " " << balance << endl;
		}

	}

	if (flag == 1)
	{
		cout << "\n NO Account Found";
	}
	file_temp.close();
	file_read.close();
	copy_content(b, a);
	cout << "\n\t Done ! Amount Added\n";
	temp_file_clear();

	//now time for deducting amount from main user
	deduct_Money(user_no, amt);
	cout << "\n Money Successfully Transferd !";
}

/* Start View All Transection */
void Accounts::viewTransfare(int user_no)
{

	int number, amount, flag = 0;
	string status;

	ifstream tr_file_read("transec.txt", ios::in);
	//cin.clear();
	system("color 2");
	cout << "\n\t" << "acc.get_Id()" << " | " << "Amount" << " | " << "CR / DR " << endl;

	while (tr_file_read)
	{
		tr_file_read >> number;
		tr_file_read >> amount;
		tr_file_read >> status;
		if (tr_file_read.eof())
		{
			break;
		}

		if (user_no == number)
		{
			cout << "\t" << number << "	      |  " << amount << "  | " << status << "  | " << endl;
			flag = 1;
		}


	}
	if (flag != 1)
	{
		cout << "\n\tNo record found";
	}
	tr_file_read.close();
}

// Employeeeeeeeeeeeeeeeeee

void FileOps::write_emp(Employee e, string fname, string lname, string phone, string data_of_birthday, string designation,
	string age,string experience, string type, int id, int password, double salary)
{
	e.createEmployee();
	ofstream file("Employee_details.txt", ios::out | ios::app);
	file << fname << " " << lname << " " << phone << " " << data_of_birthday << " " << designation << " "
		<< age << " " << experience << " " << type << " " << id << " "
		<< password << " " << salary << endl;
	cout << endl;
	e.number_system_put_Employee(id);
	file.close();
}

void Employee::search_Employee(int employee_no) //employee_no for user session for only specified user can show
{
	Employee e;
	int flag = 0;
	Employee(); //constructor call to empty variables;
	ifstream file_read("Employee_details.txt", ios::in);
	cout << "\n\tEnter Accounts number: ";
	cin >> employee_no;
	//cin.clear();

	while (file_read)
	{
		/*file_read >> fname;
		file_read >> lname;
		file_read >> phone;
		file_read >> data_of_birthday;
		file_read >> designation;
		file_read >> age;
		file_read >> ctc;
		file_read >> experience;
		file_read >> type;
		file_read >> employeeNumber;
		file_read >> password;
		file_read >> salary;*/

		if (file_read.eof())
		{
			break;
		}

		if (employee_no == e.get_Id())
		{
			system("color 6");
			cout << "\n\tAccounts Number	: " << e.get_Id();
			cout << "\n\tName			:" << e.get_fname() << " " << e.get_lname();
			cout << "\n\tPhone			:" << e.get_phone();
			cout << "\n\tDate of birth		:" << e.get_dataOfBirthday();
			cout << "\n\tDesignation		:" << getDesignation();
			cout << "\n\tAge			:" << getAge();
			cout << "\n\tExperience		:" << getExperience();
			cout << "\n\tAccounts Type		:" << e.getType();
			cout << "\n\tSalary			:" << getSalary() << " $";
			cout << "\n\n\n";
			flag = 1;
		}
	}
	if (flag != 1)
	{
		cout << "\n\tNo record found";
	}
	file_read.close();
}

void Employee::delete_Employee(int employee_no)
{
	Employee e;
	char buff;
	int flag = 0;
	string a = "Employee_details.txt";
	string b = "temp_Employee.txt";
	Employee();//constructor call to empty variables;

	ifstream file_read("Employee_details.txt", ios::in);
	ofstream file_temp("temp_Employee.txt", ios::out | ios::app);
	cout << "\n\tEnter Accounts number: ";
	cin >> employee_no;
	cin.clear();

	while (!file_read.eof())
	{
		/*file_read >> fname;
		file_read >> lname;
		file_read >> phone;
		file_read >> data_of_birthday;
		file_read >> designation;
		file_read >> age;
		file_read >> ctc;
		file_read >> experience;
		file_read >> type;
		file_read >> employeeNumber;
		file_read >> password;
		file_read >> salary;*/

		if (file_read.eof())
		{
			break;
		}
		if (employee_no == e.get_Id())
		{
			cout << e.get_fname() << " " << e.get_lname() << "\t" << e.get_phone() << "\t" << e.get_dataOfBirthday()
				<< "\t" << getDesignation() << "\t" << getAge() << "\t" << getExperience()
				<< "\t" << e.getType() << "\t" << e.get_Id() << "\t" << e.get_pass() << "\t" << getSalary() << endl;
			flag = 1;

		}
		else
		{
			file_temp << e.get_fname() << " " << e.get_lname() << "\t" << e.get_phone() << "\t" << e.get_dataOfBirthday()
				<< "\t" << getDesignation() << "\t" << getAge() << "\t" << getExperience()
				<< "\t" << e.getType() << "\t" << e.get_Id() << "\t" << e.get_pass() << "\t" << getSalary() << endl;
		}
		if (flag != 1)
		{
			cout << "\n\tNo record found";
		}

		file_temp.close();
		file_read.close();
		copy_content(b, a);

		cout << "\n\t Accounts Is Removed!\n";
	}
}

void Employee::update_Employee(int employee_no)
{
	Employee e;
	string fname;
	string lname;
	string phone;
	string data_of_birthday;
	string type;
	int flag = 0;
	string a = "Employee_details.txt";
	string b = "tempEmployee.txt";

	Employee();//constructor call to empty variables;
	ifstream file_read("Employee_details.txt", ios::in);
	ofstream file_temp("tempEmployee.txt", ios::out | ios::app);
	cout << "\n\tEnter Enployee  number: ";
	cin >> employee_no;
	//cin.clear();
	while (!file_read.eof())
	{

		/*file_read >> fname;
		file_read >> lname;
		file_read >> phone;
		file_read >> data_of_birthday;
		file_read >> designation;
		file_read >> age;
		file_read >> ctc;
		file_read >> experience;
		file_read >> type;
		file_read >> employeeNumber;
		file_read >> password;
		file_read >> salary;*/

		if (file_read.eof())
		{
			break;
		}

		if (employee_no == e.get_Id())
		{
			system("color 7");
			cout << "\n\Employee Number is: " << e.get_Id();
			cout << "\n\tFill up Details with new records: \n";

			cout << "\n\n\t New First name: ";

			cin >> fname;
			set_fname(fname);
			cin.clear();

			cout << "\n\t New Last name: ";
			cin >> lname;
			set_lname(lname);
			cin.clear();

			cout << "\n\t New phone: ";
			cin >> phone;
			set_phone(phone);
			cin.clear();

			cout << "\n\t New Birthday(01/01/1900): ";
			cin >> data_of_birthday;
			set_dataOfBirthday(data_of_birthday);
			cin.clear();

			cout << "\n New Designation: ";
			cin >> designation;
			setDesignation(designation);
			cin.clear();

			cout << "\n New Employee Age: ";
			cin >> age;
			setAge(age);
			cin.clear();

			cout << "\n New Employee Experience: ";
			cin >> experience;
			setExperience(experience);
			cin.clear();

			cout << "\n\t Current Employee Type: " << type;
			cout << "\n\t Change Type (Saving s/Other o) otherwiese press (N): ";
			char ans;
			cin >> ans;
			cin.clear();
			if (tolower(ans) == 'n')
			{
				cout << "\n\tOk !Employee type is not chenged !\n ";
			}
			else if (tolower(ans) == 's')
			{
				type = "Saving";
				setType(type);
			}
			else
			{
				type = "Other";
				setType(type);
			}
			file_temp << fname << " " << lname << " " << phone << " " << data_of_birthday << " " << designation << " "
				<< age << " " << experience << " " << type << " " << e.get_pass() << " "
				<< e.get_Id() << " " << salary << endl;
			flag = 1;
		}
		else
		{
			file_temp << fname << " " << lname << " " << phone << " " << data_of_birthday << " " << designation << " "
				<< age << " " << experience << " " << type << " " << e.get_pass() << " "
				<< e.get_Id() << " " << salary << endl;
		}

	}
	if (flag != 1)
	{
		cout << "\n\tNo record found";

	}
	file_temp.close();
	file_read.close();
	copy_content(b, a);

	cout << "\n\t Done ! Details Updated THank You.\n";
	temp_file_clear();
}

/*End mini statement function */
void Employee::show_Employees()
{
	int count = 0;
	Employee e;

	ifstream file_read("Employee_details.txt", ios::in);
	if (!file_read)
	{
		system("color 4");
		cout << "File could not be open !! Press any Key...";
		return;
	}
	system("color 4");
	cout << "\n\n\t\tEMPLOYEES LIST\n\n";
	cout << "==================================================================================================================================================\n";

	cout << "Name" << "	    		   " << "Phone" << "	" << "Data Birthday" << "	" << "Designation" << " " << "Age" << "	" << "CTC" << " " << "Experience" << "    " << "Type" << "  " << "ID" << "  " << "Password" << " " << "Salary" << endl;

	cout << "==================================================================================================================================================\n";
	string word;
	while (file_read >> word)
	{
		cout << word << "	";
		if (count >= 12)
		{
			cout << endl;
			count = 0;
		}
		count++;
	}
	file_read.close();
	cout << "\n\n\n";
}

