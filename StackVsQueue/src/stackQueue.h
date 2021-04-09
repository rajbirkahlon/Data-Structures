/*
 * stackQueue.h
 *
 *  Created on: Oct 27, 2018
 *      Author: Rajbi
 */

#ifndef STACKQUEUE_H_
#define STACKQUEUE_H_

#include <iostream>
using namespace std;
#include "arrayStack.h"

template <typename elemType>
class stackQueue {
public:
	arrayStack <elemType> stack_1;
	arrayStack <elemType> stack_2;
	stackQueue();
	void enqueue(elemType e);
	elemType dequeue();
	elemType front();
	int size();
	bool isEmpty();
	bool isFull();
};

template <typename elemType>
stackQueue<elemType>::stackQueue() {
}

template <typename elemType>
void stackQueue<elemType>::enqueue(elemType e) {
	if(stack_1.isEmpty() && stack_2.isEmpty())
		stack_1.push(e);
	else if(stack_1.isEmpty() && !stack_2.isEmpty())
		stack_2.push(e);
	else if(stack_2.isEmpty() && !stack_1.isEmpty())
		stack_1.push(e);
}

template <typename elemType>
elemType stackQueue<elemType>::dequeue() {
	elemType T;
	elemType V;
	if(!stack_2.isEmpty()) {
		for(int i = 0; i<=stack_2.stackSize(); i++) {
			V = stack_2.top();
			stack_1.push(V);
			stack_2.pop();
		}
		T = stack_1.top();
		stack_1.pop();
		return T;
	}
	else if(!stack_1.isEmpty()) {
		for(int i = 0; i<=stack_1.stackSize(); i++) {
			V = stack_1.top();
			stack_2.push(V);
			stack_1.pop();
		}
		T = stack_2.top();
		stack_2.pop();
		return T;
	}
	else if(stack_1.isEmpty() && stack_2.isEmpty()) {
		cout << "Queue is empty." << endl;
		return -1;
	}
}
template <typename elemType>
elemType stackQueue<elemType>::front() {
	elemType T;
	elemType V;
	if(!stack_2.isEmpty()) {
		for(int i = 0; i<stack_2.stackSize(); i++) {
			V = stack_2.top();
			stack_1.push(V);
		}
		T = stack_1.top();
		return T;
	}
	else if(!stack_1.isEmpty()) {
		for(int i = 0; i<stack_1.stackSize(); i++) {
			V = stack_1.top();
			stack_2.push(V);
		}
		T = stack_2.top();
		return T;
	}
	else if(stack_1.isEmpty() && stack_2.isEmpty()) {
		cout << "Queue is currently empty." << endl;
		return -1;
	}
}
template <typename elemType>
int stackQueue<elemType>::size() {
	if(stack_1.isEmpty()) {
		return stack_2.stackSize();
	}
	else if(stack_2.isEmpty()) {
		return stack_1.stackSize();
	}
	else return 0;
}
template <typename elemType>
bool stackQueue<elemType>::isEmpty() {
	if(stack_1.isEmpty() && stack_2.isEmpty()) {
		cout << "queue is empty" << endl;
		return true;
	}
	else  {
		cout << "queue is not empty" << endl;
		return false;
	}
}
template <typename elemType>
bool stackQueue<elemType>::isFull() {
	if(!stack_1.isEmpty()) {
	cout << "Limit of the queue is limited by the size of the stacks which is 100, the number of space left is currently: " << 100-stack_1.stackSize() << endl;
	}
	else if(!stack_2.isEmpty()) {
	cout << "Limit of the queue is limited by the size of the stacks which is 100, the number of space left is currently: " << 100-stack_2.stackSize() << endl;
	}
	else if(stack_1.stackSize() == 100 && stack_2.stackSize() == 100) {
		cout << "Queue is full, all 100 locations used." << endl;
		return true;
	}
	else return false;
}


#endif /* STACKQUEUE_H_ */
