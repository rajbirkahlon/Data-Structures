/*
 * maxheap.h
 *
 *  Created on: Dec 10, 2018
 *      Author: Rajbir Singh
 */

#ifndef MAXHEAP_H_
#define MAXHEAP_H_
using namespace std;
#include <iostream>


template <class elemType>
class MaxHeap {
private:
	int size;
	int maxSize;
	elemType *arr;
public:
	MaxHeap();
	~MaxHeap();
	void print();
	int insert(elemType e);
	int search(elemType e);
	void buildHeap();
	void heapify(int i, int j);
	void sort(elemType arr[], int size);
};

template <class elemType>
MaxHeap<elemType>::MaxHeap() {
	size = 0;
	maxSize = 100;
	arr = new elemType[maxSize];
}

template <class elemType>
MaxHeap<elemType>::~MaxHeap() {
	for(int i = 1; i<=size; i++) {
		delete arr[i];
	}
}

template <class elemType>
void MaxHeap<elemType>::print() {
	for(int i=1; i<=size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

template <class elemType>
int MaxHeap<elemType>::insert(elemType e) {
	size++;
	int i = 0;
	int j = i+1;
	while(e < arr[i]) {
		i++;
		if(arr[j] < e) {
			heapify(i,j);
			return ((j-i)/2)%size;
		}
	}
}

template <class elemType>
int MaxHeap<elemType>::search(elemType e) {
	for(int i=0; i<=size; i++) {
	if(arr[i] != e) {

	}
	else return i;
	}
}

template <class elemType>
void MaxHeap<elemType>::buildHeap() {
	for(int i = (size/2)-1; i >= 0; i--) {
		heapify(i, size-1);
	}
}

template <class elemType>
void MaxHeap<elemType>::heapify(int i, int j) {
	int q;
	elemType temp = arr[i];
	q = 2*i + 1;

	while(q <= j) {
		if(q < j) {
			if(arr[q] < arr[q+1]) {
				q = q+1l
			}
		}
		if(temp > arr[q])
			break;
		else {
			arr[i] = arr[q];
			i = q;
			q = 2*i + 1;
		}
	}
	arr[i] = temp;
}

template<class elemType>
void MaxHeap<elemType>::sort(elemType arr[], int size) {
	int i = arr[size];
	int p = 2*arr[size] + 1;
	int q = 2*arr[size] + 2;
	if(q<maxSize && arr[q] > arr[size]) {
		size = q;
	}
	if(p<maxSize && arr[p] > arr[size]) {
		size = p;
	}
	if(size != arr[size]) {
		swap(arr[size],arr[i]);
		heapify(arr,size);
	}
}
#endif /* MAXHEAP_H_ */
