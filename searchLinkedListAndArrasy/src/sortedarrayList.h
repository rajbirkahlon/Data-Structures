/*
 * sortedarrayList.h
 *
 *  Created on: Nov 6, 2018
 *      Author: Rajbi
 */

#ifndef SORTEDARRAYLIST_H_
#define SORTEDARRAYLIST_H_

#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <cassert>

template <class elemType>
class sortedarrayList{
private:
	int length;
	int max_length;
	elemType *list;
public:
	sortedarrayList(int size);
	sortedarrayList();
	~sortedarrayList();
	bool isEmpty() const;
	bool isFull() const;
	int listSize() const;
	int maxListSize() const;
	void print();
	void insert(elemType e);
	void removeAt(int intt);
	void clearList();

	unsigned int binarySearchIter(elemType e);
	unsigned int binarySearchRec(elemType e);
};

template <class elemType>
sortedarrayList<elemType>::sortedarrayList() {
	length = 0;
	max_length = 100;
	list = new elemType[max_length];
	assert(list != NULL);
}

template <class elemType>
sortedarrayList<elemType>::sortedarrayList(int size) {
	if(size <= 0)
		max_length = 100;
	else max_length = size;

	length = 0;
	list = new elemType[max_length];
	assert(list != NULL);
}

template <class elemType>
sortedarrayList<elemType>::~sortedarrayList(){
	delete [] list;
}

template <class elemType>
bool sortedarrayList<elemType>::isEmpty() const {
	if(length == 0){
		cout << "true" << endl;
		return true;
	}
	else {
		cout << "false" << endl;
		return false;
	}
}

template <class elemType>
bool sortedarrayList<elemType>::isFull() const {
	if(length == max_length){
		cout << "true" << endl;
		return true;
	}
	else {
		cout << "false" << endl;
		return false;
	}
}

template <class elemType>
int sortedarrayList<elemType>::listSize() const {
	cout << "length size is " << length << endl;
	return length;
}

template <class elemType>
int sortedarrayList<elemType>::maxListSize() const {
	cout << "max_length size is " << max_length << endl;
	return max_length;
}

template <class elemType>
void sortedarrayList<elemType>::print() {
	for(int i=0;i<=length;i++) {
		if(list[i] != 0 && list[i] > 0)
		cout << " " << list[i] << " ";
	}
	cout << endl;
}

template <class elemType>
void sortedarrayList<elemType>::insert(elemType e) {
	if(length == max_length) max_length++;
	for(int i=0; i<max_length; i++) {
		if(length == 0) {
			list[length] = e;
			length++;
			return;
		}

		if(length == 1) {
			if(list[length-1] >= e) {
				list[length] = list[length-1];
				list[length-1] = e;
				length++;
				return;
			}
			else {
				list[length] = e;
				length++;
				return;
			}
			list[length] = e;
			length++;
			return;
		}

		if(list[i] <= e && list[i+1] >= e) {
			for(int j=i+1;j<length;j++) {
				list[j] = list[j+1];
			}
			list[i+1] = e;
			length++;
			return;
		}

		//if(list[i] == e) {

		//}
	}
	list[max_length] = e;
	length++;
	return;
}

template <class elemType>
void sortedarrayList<elemType>::removeAt(int intt) {
	for(int i = intt;i<length;i++) {
		list[i] = list[i+1];
	}
	max_length--;
}

template <class elemType>
void sortedarrayList<elemType>::clearList() {
	for(int i=0; i<max_length+1;i++) {
		list[i] = NULL;
	}
	length = 0;
}

template <class elemType>
unsigned int sortedarrayList<elemType>::binarySearchIter(elemType e) {
	int min = 0;
	int max = length-1;
	int mid;
	bool found = false;
	while(min <= max && !found) {
		mid = (max+min)/2;
		if(list[mid] == e) {
			found = true;
		}
		else if(list[mid] > e) {
			max = mid-1;
		}
		if(list[mid] < e) {
			min = mid+1;
		}
	}
	if(found) return mid;
	else return -1;
}

template <class elemType>
unsigned int sortedarrayList<elemType>::binarySearchRec(elemType e) {
	int min = 0;
		int max = length-1;
		int mid;
		bool found = false;
			mid = (max+min)/2;
			if(list[mid] == e) {
				found = true;
			}
			else if(list[mid] > e) {
				max = mid-1;
				binarySearchRec(e);
			}
			if(list[mid] < e) {
				min = mid+1;
				binarySearchRec(e);
			}
		if(found) return mid;
		else return -1;
}

#endif /* SORTEDARRAYLIST_H_ */
