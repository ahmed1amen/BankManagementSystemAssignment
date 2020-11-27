#include <iostream>
using namespace std;
#include "nlohmann/json.hpp"
using json = nlohmann::json;
 class Helper
{
public:


	static int readChar(std::istream& stream)
	{
		char i;
		stream >> i;
		return i;


	}
	static int readDouble(std::istream& stream)
	{
		double i;
		stream >> i;
		return i;
	}
	static int readInt(std::istream& stream)
	{
		int i;
		stream >> i;
		return i;
	}

	static string readString(std::istream& stream, bool lengthValidation =false, int length=0)
	{
		string i;

		i.length();
	    stream >> i;

		if (lengthValidation)
			while (!(i.length() == length))
			{
				cout << endl << "Invalid Length Should be " << length  << endl;
				stream >> i;
			}
				
		return i;
	}



	



private:

};
