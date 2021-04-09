//============================================================================
// Name        : lab09.cpp
// Author      : Rajbir
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "LinkedListList.h"
#include "arrayList.h"
#include "sortedarrayList.h"

int main() {
	arrayList<int> list(3);
	list.isEmpty(); // true, is empty
	list.isFull(); // false
	list.insertAt(0,4); // 4
	list.insertAt(1,5); // 4 5
	list.insertAt(2,6); // 4 5 6
	list.print();
	cout << "position of entered key is: " << list.seqSearchIter(5) << endl;


	sortedarrayList<int> LIST(5);
	LIST.insert(6);
	LIST.insert(3);
	LIST.insert(12);
	//LIST.removeAt(1);
	LIST.print();
	cout << LIST.binarySearchIter(6) << endl;

	unsigned int choice = 0;
	do {
	        cout << "Choose your search type:" << endl;
	        cout << "1. Arrays: Sequential Search without recursion" << endl;
	        cout << "2. Arrays: Sequential Search with recursion" << endl;
	        cout << "3. Ordered Arrays: Binary Search without recursion" << endl;
	        cout << "4. Ordered Arrays: Binary Search with recursion" << endl;
	        cout << "5. Linked List: Search without recursion"  << endl;
	        cout << "6. Linked List: Search with recursion"
	<< endl;
	        cout << "Enter 0 to exit" << endl;
	        cout << "Your choice: ";
	        cin >> choice;
	        /****************************
	         * TODO: Implement what you will do with the
	choice
	         *****************************/
	        cout<<"\nSpecify the element to be searched for: ";
	 } while(choice!=0);
	return 0;

}

