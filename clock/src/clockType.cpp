/*
 * clockType.cpp
 *
 *  Created on: Aug 28, 2018
 *      Author: Rajbir
 */

#include "clockType.h"
#include <iostream>

clockType::clockType() {
	hr = 0;
	min = 0;
	sec = 0;
}

clockType::clockType(int hour, int minute) {
	hr = hour;
	min = minute;
	sec = 0;
}

clockType::clockType(int hour, int minute, int second) {
	hr = hour;
	min = minute;
	sec = second;
}

ostream& operator<<(ostream& os, const clockType& clk){
	os << "Time is " << clk.hr << ':' << clk.min << ':' << clk.sec << "\n";
	return os;
}

clockType operator+(const clockType &clk1, const clockType &clk2) {
	int sumHr = clk1.hr + clk2.hr;
	int sumMin = clk1.min + clk2.min;
	if (sumMin > 60) {
		sumMin = sumMin-60;
		sumHr++;
	}
	int sumSec = clk1.sec + clk2.sec;
	if (sumSec > 60) {
		sumSec = sumSec-60;
		sumMin++;
	}
	return clockType(sumHr, sumMin, sumSec);
}

clockType operator+(const clockType &clk1, int second){
	int sumSec = clk1.sec + second;
	int sumHr = clk1.hr;
	int sumMin = clk1.min;
	if(sumSec > 60) {
		sumSec = sumSec-60;
		sumMin++;
	}
	return clockType(sumHr, sumMin, sumSec);
}




