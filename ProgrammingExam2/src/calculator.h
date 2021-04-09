/*
 * calculator.h
 *
 *  Created on: Oct 30, 2018
 *      Author: Rajbi
 */
#include <string>
#include <iostream>
using namespace std;

#ifndef CALCULATOR_H_
#define CALCULATOR_H_


class calculator {
	public:
			calculator();
			~calculator();
			void add(double n);
			void subtract(double n);
			double getResult();
			void undo();
			void redo();
			void printAllOperations();
	private:
			double result;
			string keep = " ";
/*****************
 * Add any fields you need
 *****************/
};

calculator::calculator() {
	result = 0;
}

void calculator::add(double n) {

	result = result+n;
	//keep = keep + ("added" + n);
}

void calculator::subtract(double n) {
	result = result-n;
	keep = keep + ("subtracted ");
}



#endif /* CALCULATOR_H_ */
