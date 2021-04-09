/*
 * hashtablechaining.h
 *
 *  Created on: Nov 27, 2018
 *      Author: Rajbi
 */

#ifndef HASHTABLECHAINING_H_
#define HASHTABLECHAINING_H_

#include "LinkedListList.h"
#include "arrayList.h"


template <class elemType>
class HashTableChain {
private:
	int HTSize;
	arrayList<elemType> list;
	LinkedListList<elemType> LIST;
public:
	HashTableChain();
	~HashTableChain();
	void print();
	bool insert(elemType e);
	elemType search(elemType e);
	int hashFunction(elemType *key);
	int NumofLists;
};

template <class elemType>
HashTableChain<elemType>::HashTableChain() {
	cout << "Enter size of hash table: " << endl;
	cin >> HTSize;
	list = new elemType[HTSize];
	NumofLists = 0;
}

template <class elemType>
HashTableChain<elemType>::~HashTableChain() {
	for(int i=0; i<=HTSize; i++) {
		delete list[i];
	}
	cout << "Deleted successfully " << endl;
}

template <class elemType>
void HashTableChain<elemType>::print() {
	for(int i=0;i<=HTSize;i++) {
			if(list[i] != 0 && list[i] > 0)
			cout << " " << list[i] << " ";
		}
		cout << endl;
}

template <class elemType>
bool HashTableChain<elemType>::insert(elemType e) {
	int where = hashFunction(e);
	if(!list[where]) {
		list[where] = e;
}
	else {
		if(NumofLists > 0) {
			cout << "linked list already being used, cannot make another so cannot insert here. " << endl;
			return;
		}
		LIST.myListHead = list[where];
		Node<elemType> *newNode = new Node<elemType>;
		newNode->element = e;
		Node<elemType> *temp = LIST.myListHead;
		while(LIST[where]) {
			temp = temp->next;
		}
		LIST[temp] = newNode;
		NumofLists++;
	}
}


template <class elemType>
elemType HashTableChain<elemType>::search(elemType e) {
	int where = hashFunction(e);
	if(list[where] = e) return where;
	else if (list[where] != e) {
		Node<elemType> *temp = LIST[where];
		//temp->next = LIST[where];
		while(LIST[temp] != e) {
			temp = temp->next;
		}
		cout << "The element is at " << list[where] << " but at down the chain at the position " << LIST[temp] << endl;
		return LIST[temp];
	}
	else throw "Not found.";
}

template <class elemType>
int HashTableChain<elemType>::hashFunction(elemType *key) {
	int res = (key%HTSize);
	return res;
}

#endif /* HASHTABLECHAINING_H_ */
