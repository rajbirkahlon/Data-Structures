//============================================================================
// Name        : lab04.cpp
// Author      : Rajbir
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "linkedlistList.h"
using namespace std;

int main() {
	LL<int> List;
	List.isEmpty();
	List.isFull();
	List.insertEnd(22);
	List.insertEnd(32);
	List.print();
	List.insertAt(1,11);
	List.print();
	List.isEmpty();
	List.insertAt(0,44);
	List.print();
	List.insertEnd(55);
	List.print();
	List.retreiveAt(0);
	List.retreiveAt(1);
	List.removeAt(0);
	List.print();
	List.replaceAt(0, 100); //displays new number at position 0
	List.isItemAtEqual(0, 100);
}
