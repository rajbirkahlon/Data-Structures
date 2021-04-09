/*
 * arrayList.h
 *
 *  Created on: Sep 11, 2018
 *      Author: Rajbi
 */

#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <cassert>

template <class elemType>
class arrayList{
private:
	int length;
	int max_length;
	int begin;
	elemType *list;
public:
	arrayList(int size);
	arrayList();
	~arrayList();
	bool isEmpty() const;
	bool isFull() const;
	int listSize() const;
	int maxListSize() const;
	void print();
	bool isItemAtEqual(int intt, elemType e);
	void insertAt(int intt, elemType e);
	void insertEnd(elemType e);
	void removeAt(int intt);
	elemType retreiveAt(int intt);
	void replaceAt(int intt, elemType e);
	void clearList();
	elemType getMin();
};

template <class elemType>
arrayList<elemType>::arrayList() {
	length = 0;
	begin = 0;
	max_length = 100;
	list = new elemType[max_length];
	assert(list != NULL);
}

template <class elemType>
arrayList<elemType>::arrayList(int size) {
	if(size <= 0)
		max_length = 100;
	else max_length = size;

	begin = 0;
	length = 0;
	list = new elemType[max_length];
	assert(list != NULL);
}

template <class elemType>
arrayList<elemType>::~arrayList(){
	delete [] list;
}

template <class elemType>
bool arrayList<elemType>::isEmpty() const {
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
bool arrayList<elemType>::isFull() const {
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
int arrayList<elemType>::listSize() const {
	cout << "length size is " << length << endl;
	return length;
}

template <class elemType>
int arrayList<elemType>::maxListSize() const {
	cout << "max_length size is " << max_length << endl;
	return max_length;
}

template <class elemType>
void arrayList<elemType>::print() {
	for(int i=0;i<=max_length+1;i++) {
		if(list[i] != 0 && list[i] > 0)
		cout << " " << list[i] << " ";
	}
	cout << endl;
}

template <class elemType>
bool arrayList<elemType>::isItemAtEqual(int intt, elemType e) {
	if(intt < 0 || intt > length) {
		cout << "Location is not inside of array";
		return false;
	}
	if(list[intt] != e) {
		cout << "NO!" << endl;
	}
	else if(list[intt] == e) {
		cout << "YES!" << endl;
		return true;
	}
}

template <class elemType>
void arrayList<elemType>::insertAt(int intt, elemType e) {
	if(length == max_length) max_length++;
	length++;
	list[intt] = e;
}

template <class elemType>
void arrayList<elemType>::insertEnd(elemType e) {
	if(length == max_length) max_length++;
	length++;
	list[max_length] = e;
}

template <class elemType>
void arrayList<elemType>::removeAt(int intt) {
	for(int i = intt;i<length;i++) {
		list[i] = list[i+1];
	}
	max_length--;
}

template <class elemType>
elemType arrayList<elemType>::retreiveAt(int intt) {
	elemType T;
	T = list[intt];
	cout << T << endl;
	return T;
}

template <class elemType>
void arrayList<elemType>::replaceAt(int intt, elemType e) {
	list[intt] = e;
}

template <class elemType>
void arrayList<elemType>::clearList() {
	for(int i=0; i<max_length+1;i++) {
		list[i] = NULL;
	}
	length = 0;
}

template <class elemType>
elemType arrayList<elemType>::getMin() {
	if (length == 0) return -1; //no list
	elemType T;
	if (length-1 == begin) {
		T = list[begin];
		cout << list[begin];
		return T;
	}
	else {
		int i=begin, j=length-1;
		if(list[i]<list[j]) {
			length = length-1;
		}
		else if(list[i]>list[j]) {
			begin = begin+1;
		}
		return getMin();
	}
}

#endif /* ARRAYLIST_H_ */
