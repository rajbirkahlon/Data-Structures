//============================================================================
// Name        : lab1-2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "clockType.h"
#include <iostream>
using namespace std;

int main() {
	clockType c1;
	clockType c2 (10,59);
	clockType c3 (5, 10, 20);
	int sec = 10;
	cout << c1;
	cout << c2 << c3;
	cout << c1+c2;
	cout << c2+c3;
	c1 = c1+sec;
}
