//============================================================================
// Name        : lab3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "arrayList.h"
#include <fstream>
using namespace std;

int main() {
	arrayList<int> list(3);
	list.isEmpty(); // true, is empty
	list.isFull(); // false
	list.insertAt(0,4); // 4
	list.insertAt(1,5); // 4 5
	list.insertAt(2,6); // 4 5 6

	list.maxListSize(); //3
	list.listSize(); //3
	list.isFull(); // true

	list.insertAt(3,7); // 4 5 6 7
	list.insertAt(4,7); // 4 5 6 7 7

	list.isItemAtEqual(0,1); // no
	list.isItemAtEqual(0,4); // yes

	list.maxListSize(); //5
	list.listSize(); //5

	list.print(); // 4 5 6 7 7
	list.removeAt(2); // 4 5 7 7
	list.replaceAt(3, 4); // 4 5 7 4
	list.print(); // 4 5 7 4

	list.insertEnd(9); // 4 5 7 4 9

	list.print(); // 4 5 7 4 9

	list.retreiveAt(0); // 4
	list.retreiveAt(1); // 5
	list.retreiveAt(2); // 7

	list.removeAt(4);
	list.print(); // 4 5 7 4

	list.clearList();
	list.print(); // should be empty now
	list.isEmpty(); // yes, should be empty again

}
