/*
 * clockType.h
 *
 *  Created on: Aug 28, 2018
 *      Author: Rajbir
 */

#ifndef CLOCKTYPE_H_
#define CLOCKTYPE_H_
#include <iostream>
using namespace std;

class clockType {
	int hr, min, sec;
public:
	clockType();
	clockType(int hour, int minute);
	clockType(int hour, int minute, int second);
	friend ostream& operator<<(ostream& os, const clockType& clk);
	friend clockType operator+(const clockType &clk1, const clockType &clk2);
	friend clockType operator+(const clockType &clk1, int second);
};

#endif /* CLOCKTYPE_H_ */
