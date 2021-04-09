//============================================================================
// Name        : Assignment.cpp
// Author      : Rajbir
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "complexNumber.h"
#include <fstream>
using namespace std;

int main() {
	complexNumber<int> c3(3,4);
	complexNumber<int> c4(5,-6);
	complexNumber<int> c5();
	complexNumber<int> c6();

	cout << "product of complex numbers c3(3+4i) and c4(5-6i) is " << c4*c3;

	ifstream fin("complexInput.txt");
	ofstream fout("complexOutput.txt");

	try {
		complexNumber<int>::FileIO(fin, fout); // if you use, complexNumber::fileIO
	}
	catch(const char*c) {
		cout << c << endl;
	}
}
