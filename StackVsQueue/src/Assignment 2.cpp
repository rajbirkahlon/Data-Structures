//============================================================================
// Name        : Assignment.cpp
// Author      : Rajbir
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "stackQueue.h"
using namespace std;

int main() {
	try{
	stackQueue<char> charQueue;
	charQueue.isEmpty();
	charQueue.enqueue('A');
	charQueue.front();
	charQueue.enqueue('B');
	charQueue.isFull();
	cout << charQueue.dequeue() << endl;
	charQueue.isEmpty();
	charQueue.isFull();
	charQueue.enqueue('C');
	cout << charQueue.dequeue() << endl;
	charQueue.enqueue('D');
	cout << charQueue.dequeue() << endl;
	cout << charQueue.dequeue() << endl;
	cout << charQueue.dequeue() << endl;
	}
	catch(const char *e) {
		cout << e << endl;
	}
	return 0;
}

