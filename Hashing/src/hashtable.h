/*
 * hashtable.h
 *
 *  Created on: Nov 26, 2018
 *      Author: Rajbi
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include "arrayList.h"

template <class elemType>
class HashTable {
private:
	int HTSize;
	arrayList<elemType> list;
public:
	HashTable();
	~HashTable();
	void print();
	bool insert(elemType e);
	elemType search(elemType e);
	int hashFunction(elemType *key);
};

template <class elemType>
HashTable<elemType>::HashTable() {
	cout << "Enter size of hash table: " << endl;
	cin >> HTSize;
	list = new elemType[HTSize]; //
}

template <class elemType>
HashTable<elemType>::~HashTable() {
	for(int i=0; i<=HTSize; i++) {
			delete list[i];
		}
		cout << "Deleted successfully " << endl;
}

template <class elemType>
void HashTable<elemType>::print() {
	for(int i=0;i<=HTSize;i++) {
		if(list[i] != 0 && list[i] > 0)
		cout << " " << list[i] << " ";
	}
	cout << endl;
}

template <class elemType>
bool HashTable<elemType>::insert(elemType e) {
	int where = hashFunction(e);
	for(int i=0; i<HTSize; i++) {
		if(where == list[i]) {
			cout << "Item already exists here, running secondary hash function and putting it into next slot." << endl;
			int wheree = ((e%HTSize)+1);
			list[wheree] = e;
		}
		else {
			list[where] = e;
		}
	}
}

template <class elemType>
elemType HashTable<elemType>::search(elemType e) {
	int where = hashFunction(e);
	if(list[where]) return where;
	else {
		cout << "Not found" << endl;
		return;
	}
}

template <class elemType>
int HashTable<elemType>::hashFunction(elemType *key) {
	int res = (key%HTSize);
	return res;
}


#endif /* HASHTABLE_H_ */
