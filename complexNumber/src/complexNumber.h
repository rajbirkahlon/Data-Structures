/*
 * complexNumber.h
 *
 *  Created on: Sep 17, 2018
 *      Author: Rajbi
 */

#ifndef COMPLEXNUMBER_H_
#define COMPLEXNUMBER_H_
using namespace std;
#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <cctype>


template <class elemType>
class complexNumber {
private:
	elemType real, imaginary;
public:
	complexNumber();
	complexNumber(elemType R, elemType I);
	static void FileIO(istream &in, ostream &out);

	friend complexNumber operator+(const complexNumber &c1, const complexNumber &c2) {
		elemType sumReal = c1.real + c2.real;
			elemType sumImag = c1.imaginary+c2.imaginary;
			return complexNumber(sumReal, sumImag);
	}

	friend complexNumber operator*(const complexNumber &c1, const complexNumber &c2) {
		complexNumber<elemType> c3;
		c3.real = ((c1.real*c2.real) + ((-1)*c1.imaginary*c2.imaginary));
		c3.imaginary = (c1.real*c2.imaginary)+(c1.imaginary*c2.real);
		return c3;
		}

	friend complexNumber operator-(const complexNumber &c1, const complexNumber &c2) {
		elemType sumReal = c1.real - c2.real;
		elemType sumImag = c1.imaginary-c2.imaginary;
		return complexNumber(sumReal, sumImag);
			}

	friend ostream& operator<<(ostream& os, const complexNumber &c1) {
		os << c1.real << "+" <<  c1.imaginary << "i" << endl;
		return os;
	}

	friend istream& operator>>(istream& is, complexNumber &c1) {
		char symbol;
		elemType num;
		is >> skipws >> num;
		c1.real = num;
		if(symbol == '-') {
			c1.real = -c1.real;
				}

		is >> skipws >> symbol;

		is >> num;
		c1.imaginary = num;
		if(symbol == '-') {
			c1.imaginary = -c1.imaginary;
		}

		is >> skipws >> symbol;
		is >> skipws >> symbol;

		return is;
	}
};

template <class elemType>
void complexNumber<elemType>::FileIO(istream &in, ostream &out) {
	complexNumber<elemType> c1, c2;
	in >> c1;
	in >> c2;

	out << c1*c2;
}

template <class elemType>
complexNumber<elemType>::complexNumber() {
	real = 0;
	imaginary = 0;
}

template <class elemType>
complexNumber<elemType>::complexNumber(elemType R, elemType I) {
	real = R;
	imaginary = I;
}

#endif /* COMPLEXNUMBER_H_ */
