//============================================================================
// Name        : ProgrammingExam1.cpp
// Author      : Rajbir
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;
#include "myDate.h"

int main() {
	myDate d1;

	ifstream fin("birthdays.txt");
	ofstream fout("birthday_old_to_young.txt");

	try {
		myDate::FileIO(fin, fout);
	}
	catch(const char*c) {
		cout << c << endl;
	}
}
