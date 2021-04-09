
#ifndef HELPER_H_
#define HELPER_H_

#include <iostream>
using namespace std;

void fillRandom(int *Array, const unsigned int size){
	for(unsigned int i = 0; i < size; i++){
		//Array[i] = rand(); error in file downloaded from Canvas?
	}
}

void print(int *Array, const unsigned int size){
	for(unsigned int i = 0; i < size; i++){
		cout << Array[i] << ", ";
	}
	cout << endl;
}

#endif /* HELPER_H_ */
