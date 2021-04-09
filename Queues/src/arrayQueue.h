/*
 * arrayQueue.h
 *
 *  Created on: Oct 28, 2018
 *      Author: Rajbi
 */

#ifndef ARRAYQUEUE_H_
#define ARRAYQUEUE_H_

#include <iostream>
using namespace std;
#include <vector>
#include <string>

template <class elemType>
class arrayQueue {
	int f, b;
	int length;
	elemType *queue;
public:
	arrayQueue();
	~arrayQueue();

	int size();
	void maxSize();
	bool isEmpty() const;
	bool isFull() const;

	elemType front();
	elemType dequeue();
	void enqueue(elemType e);

	void print();
};

template <class elemType>
arrayQueue<elemType>::arrayQueue() {
	f = -1;
	b = -1;
	length = 0;
	queue = new elemType[100];
}

template <class elemType>
arrayQueue<elemType>::~arrayQueue() {
	delete [] queue;
}

template <class elemType>
int arrayQueue<elemType>::size() {
	return length;
}

template <class elemType>
void arrayQueue<elemType>::maxSize() {
	cout << "Max size is decided by memory space dedicated to be used for the queue, which is in this case 100" << endl;
}

template <class elemType>
bool arrayQueue<elemType>::isEmpty() const {
	if(f == -1 && b == -1) {
		return true;
	}
	else return false;
}

template <class elemType>
bool arrayQueue<elemType>::isFull() const {
	if(b == 100) {
		return true;
	}
	else return false;
}

template <class elemType>
elemType arrayQueue<elemType>::front() {
	elemType T;
	T = queue[f];
	return T;
}

template <class elemType>
void arrayQueue<elemType>::enqueue(elemType e) {
	if(f == -1 && b == -1) {
			f = 0;
			b = 0;
			queue[f] = e;
			queue[b] = e;
			length++;
		}
	else {
		b++;
		queue[b] = e;
		length++;
	}
}

template <class elemType>
elemType arrayQueue<elemType>::dequeue() {
	elemType T;
	if(f == 0 && b == 0) {
		T = queue[f];
		f = -1;
		b = -1;
		length--;
		return T;
	}
	else {
		T = queue[f];
		f++;
		length--;
		return T;
	}
}

template <class elemType>
void arrayQueue<elemType>::print() {
	cout << "Queue is: " << endl;
	//for(int j=0; j<length; j++)
	//	cout << queue[f] << endl

	for(int j=0; j<length; j++) {
		cout << queue[f+j] << endl;
		}
}

#endif /* ARRAYQUEUE_H_ */
