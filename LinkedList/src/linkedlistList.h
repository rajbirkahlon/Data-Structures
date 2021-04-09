/*
 * linkedlistList.h
 *
 *  Created on: Sep 18, 2018
 *      Author: Rajbi
 */

#ifndef LINKEDLISTLIST_H_
#define LINKEDLISTLIST_H_
using namespace std;

template <class type>
class LLNode {
//private:
public:
	type elem;
	LLNode* next;
	LLNode();
	LLNode(type eleme, LLNode* nextt);
	~LLNode();
	type getElement() const;
	void setElement(type elem);
	LLNode* getNext() const;
	void setNext(LLNode* next);
};

template <class type>
LLNode<type>::LLNode() {
	elem = 0;
	next = NULL;
}


template <class type>
LLNode<type>::LLNode(type eleme, LLNode* nextt) {
	elem = eleme;
	next = nextt;
}

template <class type>
LLNode<type>::~LLNode() {

}

template <class type>
type LLNode<type>::getElement() const {
	return elem;
}

template <class type>
void LLNode<type>::setElement(type elem) {
	this->elem = elem;
}

template <class type>
LLNode<type>* LLNode<type>::getNext() const {
	return next;
}

template <class type>
void LLNode<type>::setNext(LLNode* next) {
	this->next = next;
}

template <class type>
class LL {
//private:
public:
	LLNode<type> *head;
	LLNode<type> *tail;

	LL();
	~LL();
	bool isEmpty() const;
	bool isFull() const;
	int listSize() const;
	int maxListSize() const;
	void print();
	bool isItemAtEqual(int intt, type typ);
	void insertAt(int intt, type typ); //done
	void insertEnd(type typ); //done
	void removeAt(int intt);
	type retreiveAt(int intt);
	void replaceAt(int intt, type typ);
	void clearList();
};

template <class type>
LL<type>::LL() {
	head = NULL;
	tail = NULL;
}

template <class type>
LL<type>::~LL() {
	LLNode<type> *current = head;
	while(current != NULL) {
		LLNode<type> *temp = current->getNext();
		delete current;
		current = temp;
	}
}

template <class type>
bool LL<type>::isEmpty() const {
	if(head == NULL) {
		cout << "true" << endl;
		return true;
	}
	else {
		cout << "false" << endl;
		return false;
	}
}

template <class type>
bool LL<type>::isFull() const {
	cout << "List can not be full" << endl;
	return false;
}

template <class type>
int LL<type>::listSize() const {
	int size_of_list = 0;
	LLNode<type> *current = head;
	while(current) {
		current = current->next;
		size_of_list++;
	}
	return size_of_list;
}

template <class type>
int LL<type>::maxListSize() const {
	cout << "No max size of a linked list" <<  endl;
	return -1;
}

template <class type>
void LL<type>::print() {
	LLNode<type> *node = head;
	if(!head) cout << "no list found" << endl;
	int count = 0;
	while(node) {
		count++;
		cout << " " << count << ")" << node->getElement();
		node = node->getNext();
	}
	if(count == 0)
		cout <<"Linked list is empty" << endl;
	cout << endl;
}

template <class type>
bool LL<type>::isItemAtEqual(int intt, type typ) {
	LLNode<type> *node = head;
	int count = 0;
	while(node) {
		if(count == intt) {
			if(node->getElement() == typ) {
				cout << "true" << endl;
				return true;
			}
			else {
				cout << "false" << endl;
				return false;
			}
		}
		count++;
	}
}


template <class type>
void LL<type>::insertAt(int intt, type typ) {
	LLNode<type> *node = new LLNode<type>(typ, NULL);
	LLNode<type> *current = head;
	int count = 0;

	if(intt == 0) {
		node->setNext(head);
		head = node;
	}

	while(current && current->next) {
		if(count < intt) {
			node->next = current->next;
			current->setNext(node);
		}
			current = current->next;
			count++;
	}
	if(count == intt) {
		node->setNext(current);
	}
}

template <class type>
void LL<type>::insertEnd(type typ) {
	LLNode<type> *node = new LLNode<type>(typ, NULL);
	if(!head) {
		head = node;
		tail = node;
		return;
	}
	tail->setNext(node);
	tail = node;
	if(!head)
		head = node;
}

template <class type>
void LL<type>::removeAt(int intt) {
	LLNode<type> *temp = NULL;
	LLNode<type> *current = head;
	int count = 0;

	if(intt == 0)
		head = head->next;

	while(current && current->next) {
		if(count < intt) {
			temp->next = current->next;
			current->next = temp;
			delete temp;
			}
			current = current->next;
			count++;
		}
		if(count == intt) {
			current->next = NULL;
			delete tail;
			tail = current;
		}
}

template <class type>
type LL<type>::retreiveAt(int intt) {
	LLNode<type> *current = head;
	int count = 0;
	if(intt == 0) {
		cout << "element is " << current->getElement() << endl;;
		return current->getElement();
	}
	while(current) {
		if(count < intt) {
		current = current->next;
		count++;
		}
		if(count == intt) {
			cout << "element is " << current->getElement() << endl;
			return current->getElement();
		}
	}
	return current->getElement();
}

template <class type>
void LL<type>::replaceAt(int intt, type typ) {
	LLNode<type> *current = head;
		int count = 0;
		if(intt == 0) {
			current->setElement(typ);
			cout << current->getElement() << endl;
			return;
		}
		if(count < intt) {
			current = current->next;
			count++;
			}
			if(count == intt) {
				current->setElement(typ);
				cout << current->getElement() << endl;
			}
		}

template <class type>
void LL<type>::clearList() {
	~LL();
}

#endif /* LINKEDLISTLIST_H_ */
