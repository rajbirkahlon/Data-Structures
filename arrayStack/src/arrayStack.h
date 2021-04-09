/*
 * arrayStack.h
 *
 *  Created on: Oct 14, 2018
 *      Author: Rajbi
 */

#ifndef ARRAYSTACK_H_
#define ARRAYSTACK_H_

#include <iostream>
using namespace std;
#include <vector>
#include <string>

template <class elemType>
class arrayStack{
	int index;
	int length;
	elemType *stack;
public:
	arrayStack();
	~arrayStack();

	int stackSize() const;
	void maxSize() const;
	bool isEmpty() const;

	void print();

	elemType pop();
	void push(elemType e);
	elemType top();
};

template <class elemType>
arrayStack<elemType>::arrayStack() {
	index = -1;
	length = 0;
	stack = new elemType[100];
}

template <class elemType>
arrayStack<elemType>::~arrayStack(){
	delete [] stack;
}

template <class elemType>
bool arrayStack<elemType>::isEmpty() const {
	if(length == 0){
		//cout << "true" << endl;
		return true;
	}
	else {
		//cout << "false" << endl;
		return false;
	}
}

template <class elemType>
int arrayStack<elemType>::stackSize() const {
	//cout << "stack size is " << length << endl;
	return length;
}

template <class elemType>
void arrayStack<elemType>::maxSize() const {
	cout << "Max size is decided by memory space available to be used for the stack, but lets just say 100" << endl;
}

template <class elemType>
void arrayStack<elemType>::print() {
	cout << "Stack is as follows: " << endl;
	for(int j=1; j<index+1; j++) {
		cout << stack[index-j] << endl;
	}
	//cout << endl;
}


template <class elemType>
void arrayStack<elemType>::push(elemType e) {
	if(index == -1) index = 0;
	stack[index] = e;
	index++;
	length++;
}

template <class elemType>
elemType arrayStack<elemType>::pop() {
	index --;
	length--;
	elemType T;
	//stack[index] = NULL;
	T = stack[index];
	if(index == 0) index = -1;
	return T;
}

template <class elemType>
elemType arrayStack<elemType>::top() {
	elemType T;
	T = stack[index-1];
	//cout << "top of stack is "<< T << endl;
	return T;
}

#endif /* ARRAYSTACK_H_ */
