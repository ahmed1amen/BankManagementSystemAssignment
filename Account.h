#pragma once
#include "Person.h"
#include<iostream>
#include<string>
using namespace std;

class Accounts: public Person
{
private:
	int balance;
public:

	Accounts()
	{
		balance = 0;
	}
	/*~Accounts() {}*/
	double getBalance();
	void setBalance(double);

	void createAccount(); 		//functionv for openning new account
	void CurrentBalance(int);	//balance chack
	void searchDetails(int);	//function to search details of perticular user
	void Deposit(int, int);     //Deposit
	void deduct_Money(int, int); //Deduct Money
	void viewTransfare(int); //view all transections 
	void transfareTO(int); //For tranfering fund between tow users
	void user_menu(int);

	void login_user(int, int);	//login function


	void delete_details(int);		//function for deleting record
	void update_details(int); 	//function for updating record
	//void close_details(int);  //function for close record
	void showDetails(); //function for showing account details
	void number_system_put(int n1);
	int get_last_index();  //account number automation 
	void ministatement(int); //function for ministatement



};





