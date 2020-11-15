#include "Encrypt.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

string Encrypt::f_encryp(string str)
{
    cout << "Please enter a string: \t";
    cin >> str;

        //using switch case statements
        for (int i = 0; (i < 100 && str[i] != '\0'); i++)
            str[i] = str[i] + 2; //the key for encryption is 3 that is added to ASCII value
        cout << "\nDecrypted string: " << str << endl;
 
        return str;

}
