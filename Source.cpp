#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string comeback;
	string path = "history.txt";
	
	fstream fs;

	//меню
menu:
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~ Game of Heroes ~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\tStart" << endl;
	cout << "\t\tHistory" << endl;
	cout << "\t\tAbout" << endl;
	cout << "\t\tExit" << endl;

	cout << "What do you want? : ";

	string choose_menu;
	cin >> choose_menu;

	return 0;
}