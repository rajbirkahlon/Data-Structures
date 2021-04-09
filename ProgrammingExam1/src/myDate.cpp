/*
 * myDate.cpp
 *
 *  Created on: Sep 25, 2018
 *      Author: Rajbi
 */

#include "myDate.h"


myDate::myDate() {
	month = 1;
	date = 1;
	year = 2000;
}

myDate::myDate(int m, int d, int y) {
	month = m;
	date = d;
	year = y;
}

ostream& operator <<(ostream &os, myDate& d) {
	os << d.month << "/" << d.date << "/" << d.year;
	return os;
}

istream& operator>>(istream& is, myDate& d){
	int num;
	char slash;

	is >> skipws >> num;
	d.month = num;

	is >> skipws >> slash;

	is >> skipws >> num;
	d.date = num;

	is >> skipws >> slash;

	is >> skipws >> num;
	d.year = num;

	return is;
}

bool operator>(const myDate &d1, const myDate &d2) {
	if(d1.year < d2.year)
		return false;
	if(d1.year > d2.year)
		return true;
	if(d1.year == d2.year && d1.month < d2.month)
		return false;
	if(d1.year == d2.year && d1.month > d2.month)
		return true;
	if(d1.year == d2.year && d1.month == d2.month && d1.date < d2.date)
		return false;
	if(d1.year == d2.year && d1.month == d2.month && d1.date > d2.date)
		return true;
	if(d1.year == d2.year && d1.month == d2.month && d1.date == d2.date)
		return false;
}

bool operator<(const myDate &d1, const myDate &d2) {
	if(d1.year < d2.year)
		return true;
	if(d1.year > d2.year)
		return false;
	if(d1.year == d2.year && d1.month < d2.month)
		return true;
	if(d1.year == d2.year && d1.month > d2.month)
		return false;
	if(d1.year == d2.year && d1.month == d2.month && d1.date < d2.date)
		return true;
	if(d1.year == d2.year && d1.month == d2.month && d1.date > d2.date)
		return false;
	if(d1.year == d2.year && d1.month == d2.month && d1.date == d2.date)
		return false;
}

bool operator<=(const myDate &d1, const myDate &d2) {
	if(d1.year < d2.year)
		return true;
	if(d1.year > d2.year)
		return false;
	if(d1.year == d2.year && d1.month < d2.month)
		return true;
	if(d1.year == d2.year && d1.month > d2.month)
		return false;
	if(d1.year == d2.year && d1.month == d2.month && d1.date < d2.date)
		return true;
	if(d1.year == d2.year && d1.month == d2.month && d1.date > d2.date)
		return false;
	if(d1.year == d2.year && d1.month == d2.month && d1.date == d2.date)
		return true;
}

bool operator>=(const myDate &d1, const myDate &d2) {
	if(d1.year < d2.year)
		return false;
	if(d1.year > d2.year)
		return true;
	if(d1.year == d2.year && d1.month < d2.month)
		return false;
	if(d1.year == d2.year && d1.month > d2.month)
		return true;
	if(d1.year == d2.year && d1.month == d2.month && d1.date < d2.date)
		return false;
	if(d1.year == d2.year && d1.month == d2.month && d1.date > d2.date)
		return true;
	if(d1.year == d2.year && d1.month == d2.month && d1.date == d2.date)
		return true;
}

void myDate::FileIO(istream& is, ostream& os) {
	myDate d1, d2, d3, d4;
	string s1, s2, s3, s4;
	is >> d1;
	is >> s1;
	is >> d2;
	is >> s2;
	is >> d3;
	is >> s3;
	is >> d4;
	is >> s4;

	if(d1<d2) {
		if(d1<d3) {
			if(d1<d4) {
				os << s1 << "( Birthday: " << d1 << ") is oldest. ";
			}
		}
	}

	if(d2<d1) {
			if(d2<d3) {
				if(d2<d4) {
					os << s2 << "(Birthday: " << d2 << ") is oldest. ";
				}
			}
		}

	if(d3<d1) {
			if(d3<d2) {
				if(d3<d4) {
					os << s3 << "(Birthday: " << d3 << ") is oldest. ";
				}
			}
		}

	if(d4<d2) {
			if(d4<d3) {
				if(d4<d1) {
					os << s4 << "(Birthday: " << d4 << ") is oldest. ";
				}
			}
		}

	if(d1>d2) {
			if(d1>d3) {
				if(d1>d4) {
					os << s1 << "(Birthday: " << d1 << ") is youngest. ";
				}
			}
		}

		if(d2>d1) {
				if(d2>d3) {
					if(d2>d4) {
						os << s2 << "(Birthday: " << d2 << ") is youngest. ";
					}
				}
			}

		if(d3>d1) {
				if(d3>d2) {
					if(d3>d4) {
						os << s3 << "(Birthday: " << d3 << ") is youngest. ";
					}
				}
			}

		if(d4>d2) {
				if(d4>d3) {
					if(d4>d1) {
						os << s4 << "(Birthday: " << d4 << ") is youngest. ";
					}
				}
			}
}
