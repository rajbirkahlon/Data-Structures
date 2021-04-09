//============================================================================
// Name        : Lab.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "hashtable.h"
#include "hashtablechaining.h"
int main() {
	unsigned int choice = 0;
	do {
        cout << "Choose your hashing method:" << endl;
        cout << "7. Arrays: Hashing with linear probing" << endl;
        cout << "8. Arrays: Hashing with chaining" <<endl;
        cout << "9. Arrays: Hashing with quadratic probing (optional)" << endl;
        cout << "Enter 0 to exit" << endl;
        cout << "Your choice: ";
        cin >> choice;
        /****************************
         *****************************/
        if(choice == 7) {
        	HashTable<int> HT;
        	HT.insert(2);
        	HT.insert(3);
        	HT.search(2);
        	HT.print();
        }
        else if (choice == 8) {
        	HashTableChain<int> HTC;
        	HTC.insert(2);
        	HTC.insert(7);
        	HTC.search(7);
        	HTC.print();
        }
        cout<<"\nSpecify the element to be searched for: ";
 } while(choice!=0);
return 0;
}
