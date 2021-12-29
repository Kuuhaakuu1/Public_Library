#include <iostream>
#include <fstream>
#include "Library.h"
#include "Client.h"
#include <windows.h>
using namespace std;

Book books[100000];

int main()
{
	Library library;
	cout << "                                 Welcome to the Library" << endl << endl;
	int options;
	cout << "1. Client       " << "2. Librarian    " << " 3. Exit " << endl;
	cin >> options;
	if (options == 1) {
		system("CLS");
		library.ClientMenu();
	}
	else if (options == 2) {
		system("CLS");
		library.LibrarianMenu();
	}
	system("PAUSE");
	system("CLS");
	return 0;
};