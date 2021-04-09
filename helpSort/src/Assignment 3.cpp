#include <iostream>
#include "helper.h"
#include "sorting.h"
using namespace std;

int main() {
	unsigned int size;
	cout << "Enter the size of the array: ";
	int* Array = new int[size];
	cin >> size;

	unsigned int choice = 0;
	do {
			fillRandom(Array, size);
	        cout << "Choose your sorting algorithm:" << endl;
	        cout << "1. Bubble Sort" << endl;
	        cout << "2. Selection Sort" << endl;
	        cout << "3. Insertion Sort" << endl;
	        cout << "4. Merge Sort"  << endl;
	        cout << "5. Quick Sort"  << endl;
	        cout << "6. Shell Sort" << endl; //Optional
	        cout << "Enter 0 to exit" << endl;
	        cout << "Your choice: ";

	        cin >> choice;

	        cout << "Unsorted Array: ";
	        print(Array, size);

	        /****************************
			 * TODO: Implement what you will do with the choice
			 *****************************/
	        cout << "Sorted Array: ";
	        print(Array, size);

	 } while(choice!=0);

	 delete [] Array;

	return 0;
}
