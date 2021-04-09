/*
 * myDate.h
 *
 *  Created on: Sep 25, 2018
 *      Author: Rajbi
 */

#ifndef MYDATE_H_
#define MYDATE_H_

#include <iostream>
using namespace std;

class myDate {
private:
	int month, date, year;
public:
	myDate();
	myDate(int m, int d, int y);
	myDate get_date();
	friend istream& operator>>(istream& is, myDate& d);
	friend bool operator>(const myDate &d1, const myDate &d2);
	friend bool operator<(const myDate &d1, const myDate &d2);
	friend bool operator<=(const myDate &d1, const myDate &d2);
	friend bool operator>=(const myDate &d1, const myDate &d2);
	static void FileIO(istream& is, ostream& os);
	friend ostream& operator <<(ostream &os, myDate& d);
};

#endif /* MYDATE_H_ */
