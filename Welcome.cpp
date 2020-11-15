#include "Welcome.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

void Welcome::intro()
{

	system("cls");
	system("Color B");
	cout << "\n";
	cout << "              .oPYo.              8      o     o                                                          o  .oPYo.                 o               " << endl;
	cout << "              8   `8              8      8b   d8                                                          8  8                      8                " << endl;
	cout << "              o8YooP' .oPYo. odYo. 8  .o  8`b d'8 .oPYo. odYo. .oPYo. .oPYo. .oPYo. ooYoYo. .oPYo. odYo.  o8P `Yooo. o    o .oPYo.  o8P .oPYo. ooYoYo." << endl;
	cout << "              8   `b .oooo8 8' `8 8oP'   8 `o' 8 .oooo8 8' `8 .oooo8 8    8 8oooo8 8' 8  8 8oooo8 8' `8   8      `8 8    8 Yb..     8  8oooo8 8' 8  8" << endl;
	cout << "              8    8 8    8 8   8 8 `b.  8     8 8    8 8   8 8    8 8    8 8.     8  8  8 8.     8   8   8       8 8    8   'Yb.   8  8.     8  8  8" << endl;
	cout << "              8oooP' `YooP8 8   8 8  `o. 8     8 `YooP8 8   8 `YooP8 `YooP8 `Yooo' 8  8  8 `Yooo' 8   8   8  `YooP' `YooP8 `YooP'   8  `Yooo' 8  8  8" << endl;
	cout << "              :......::.....:..::....::.....::::..:.....:..::..:.....::...8 :.....:..:..:..:.....:..::..::..::.....::....8 :.....:::..::.....:..:..:..." << endl;
	cout << "              ::::::::::::::Basics::::::::::::::::::::::::::::::::::::::ooP'.:::::::::::::::::::::::::::::::::::::::::::DS'.:::::::::::::::::::::::::::" << endl;
	cout << "              ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::...::::::::::::::::::::::::::::::::::::::::::::...:::::::::::::::::::::::::::::" << endl << endl;
	cout << "						WELCOME";
	for (int a = 1; a <= 8; a++) // Change 'a<?' to how many * you want
	{
		Sleep(400);
		cout << "...";
	}
	cout << "\n\n                                                            MADE BY:																	" << endl;
	cout << "                                                            I-    Eslam Abdelbasset                                                            " << endl;
	cout << "                                                            II-   Ahmed Kamal                                                           " << endl;
	cout << "                                                            III-  Aya Abdelhady                                                            " << endl;
	cout << "\n" << endl;
	cout << "                                                       ********************************" << endl;
	cout << "                                                       *********   Bank Menu   ********" << endl;
	cout << "                                                       ********************************" << endl;


}