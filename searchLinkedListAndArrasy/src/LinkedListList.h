/*
*  linkedListList.h
*
*  Created on: Oct 23, 2018
*  Author: Mahima
*/
#ifndef LINKEDLISTLIST_H_
#define LINKEDLISTLIST_H_
#include <iostream>
#include <assert.h>
using namespace std;

template<class elemType>
struct Node{
	elemType element;
	Node* next;
	elemType getElement() const;
	Node(){
		next = NULL;
	}
};

template <class elemType>
class LinkedListList{
	public:
	LinkedListList();
	bool isEmpty() const;                   //Checks if list is empty
	bool isFull() const;                    // Checks if list is full
	unsigned int listSize() const;          // Returns the size of the list
	unsigned int maxListSize() const; // Returns the maximum possible size of the list
	void print() const;                                // Prints the elements of the list on the console
	bool isItemAtEqual(const unsigned int, const elemType &) const; // Checks if the item at position matches the 2nd parameter
	void insertAt(const unsigned int, const elemType &);           // Inserts 2nd parameter at position
	void insertEnd(const elemType&);              // Inserts object to end of the list
	void removeAt(const unsigned int);                       // Removes object at position
	elemType retreiveAt(const unsigned int) const;                 // Retrieves object at position
	void replaceAt(const unsigned int, const elemType &);          // Replaces object at position with 2nd parameter
	void clearList();                             // Empties the list

	bool seqSearchIter(elemType e);
	bool seqSearchRec(elemType e);

	LinkedListList &operator=(const LinkedListList &);
	virtual ~LinkedListList();

	private:
	unsigned int size;

	Node<elemType>* myListHead;
	Node<elemType> *getNodeAt(const unsigned int) const;
};
//This function is O(1)
template<class elemType>
LinkedListList<elemType>::LinkedListList() {
	myListHead = NULL;
	size = 0;
}
//This function is O(1)
template<class elemType>
bool LinkedListList<elemType>::isEmpty() const {
	if(size == 0)
	return true;
	return false;
}
//This function is O(1)
template<class elemType>
bool LinkedListList<elemType>::isFull() const {
	return false;
}
//This function is O(1)
template<class elemType>
unsigned int LinkedListList<elemType>::listSize() const {
	return size;
}
//This function is O(1)
template<class elemType>
unsigned int LinkedListList<elemType>::maxListSize() const {
	return __INT_MAX__;
}
//This function is O(n)
template<class elemType>
void LinkedListList<elemType>::print() const {
	Node<elemType> *temp = myListHead;
	while(temp){
		cout << temp->element << ", ";
		temp = temp->next;
}
	cout << endl;
}
//This function is O(n)
template<class elemType>
bool LinkedListList<elemType>::isItemAtEqual(const unsigned int position, const elemType &element) const {
	if(position > size){
		throw "Out of bounds.";
}
	Node<elemType> *node = getNodeAt(position);
	if(node->element == element)
		return true;
	return false;
}
//This function is O(n)
template<class elemType>
void LinkedListList<elemType>::insertAt(const unsigned int position, const elemType &element) {
if (this->isFull()){
	throw "List if full";
}
if(position > size+1){
	throw "Inserting out of bounds.";
}
Node<elemType> *newNode = new Node<elemType>;
newNode->element = element;
if(size > 1){
	if(position == 1){
		newNode->next = myListHead;
		myListHead = newNode;
	}
	else{
		Node<elemType> *node = getNodeAt(position-1);
		newNode->next = node->next;
		node->next = newNode;
	}
}
else{
	myListHead = newNode;
}
size++;
}
//This function is O(n). Can be O(1) if tail is stored.
template<class elemType>
void LinkedListList<elemType>::insertEnd(const elemType &element) {
	if (this->isFull()){
		throw "List if full";
}
	Node<elemType> *newNode = new Node<elemType>;
	newNode->element = element;
	newNode->next = NULL;
	if(size > 0){
		Node<elemType> *node = getNodeAt(size);
		node->next = newNode;
	}
	else{
		myListHead = newNode;
	}
	size++;
}
//This function is O(n)
template<class elemType>
void LinkedListList<elemType>::removeAt(const unsigned int position) {
	if(position > size){
		throw "Removing out of bounds.";
	}
	if(position == 0) {
		Node<elemType> *temp = myListHead;
		myListHead = myListHead->next;
		delete temp;
	}
	else {
		Node<elemType> *node = getNodeAt(position-1);
		Node<elemType> *elemToDel = node->next;
		if(position == size) {
			node->next = NULL;
		}
		else {
			node->next = elemToDel->next;
		}
		delete elemToDel;
		size--;
	}
}
//This function is O(n)
template<class elemType>
elemType LinkedListList<elemType>::retreiveAt(const unsigned int position) const{
	if(position > size){
		throw "Retrieving out of bounds.";
	}
	Node<elemType> *node = getNodeAt(position);
	return node->element;
}
//This function is O(n)
template<class elemType>
void LinkedListList<elemType>::replaceAt(const unsigned int position, const elemType &element) {
	if(position > size){
		throw "Retrieving out of bounds.";
	}
	Node<elemType> *node = getNodeAt(position);
	node->element = element;
}
//This function is O(n)
template<class elemType>
void LinkedListList<elemType>::clearList() {
	Node<elemType> *temp = myListHead;
	while(temp){
		Node<elemType> *elemToDel = temp;
		temp = temp->next;
		delete elemToDel;
	}
	myListHead = NULL;
	size = 0;
}
//This function is O(n)
template<class elemType>
LinkedListList<elemType>& LinkedListList<elemType>::operator =(const LinkedListList<elemType>& constLLList) {
	clearList();
	Node<elemType>* temp = constLLList.myListHead;
	Node<elemType>* temp_this = NULL;
	while(temp){
		Node<elemType>* newNode = new Node<elemType>;
		newNode->element = temp->element;
		if(temp_this == NULL){
			myListHead = newNode;
		}
		else{
			temp_this->next = newNode;
		}
		temp_this = newNode;
		temp = temp->next;
	}
	size = constLLList.listSize();
	return *this;
}
//This function is O(n)
template<class elemType>
LinkedListList<elemType>::~LinkedListList() {
	clearList();
}
//This function is O(n)
template<class elemType>
Node<elemType> *LinkedListList<elemType>::getNodeAt(const unsigned int position) const{
	unsigned int i = 1;
	Node<elemType> *temp = myListHead;
	while(i < position){
		assert(temp != NULL);
		temp = temp->next;
		i++;
	}
	return temp;
}

template<class elemType>
bool LinkedListList<elemType>::seqSearchIter(elemType e) {
	bool found = false;
	Node<elemType> temp = myListHead;
	while(temp) {
	elemType ele = retreiveAt(temp);
	if(ele == e) {
		found = true;
	}
	else temp = temp->next;
}
	return found;
}

template<class elemType>
bool LinkedListList<elemType>::seqSearchRec(elemType e) {
	bool found = false;
	Node<elemType> temp = myListHead;

	elemType ele = retreiveAt(temp);
	if(ele == e) {
		found = true;
		}
	else {
		temp = temp->next;
		seqSearchRec(e);
	}
	return found;
}

#endif /* LINKEDLISTLIST_H_ */
