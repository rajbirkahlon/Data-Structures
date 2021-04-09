//============================================================================
// Name        : ProgrammingExam3.cpp
// Author      : Rajbir
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include <string>
using namespace std;

#define MAXBOOKS 1000

void read(string filename, string* books) {
	//ifstream fin(filename);
	int index = 0;
	//while(!fin.eof()) {
	//	getline(fin, books[index++]);
	//}
}

int exponentialSearch(string* books, string e) { //added string e in paramter since that is the book we are looking for in the list of books
	int index = 1;
	while(index < books->size() && books[index-1] < e){ // while index is less than size of all books list OR the element at index-1 is less than element we are looking for
		index = 2*index;
	}
	//binary search now
	int p,q,mid;
	p = 0;
	q = index;
	while(p<q) {
		mid = (p+q)/2;
		if(books[p] < e && books[q] > e) { //edge case test
			throw "not found";
		}
		if(books[mid] < e) {
			p = mid; //if element greater than mid, make the mid the min
		}
		if(books[mid] > e) {
			q = mid; //if element less than mid, make the min the max
		}
		if(books[mid] == e) {
			return mid; //return index where book was found
		}
		}
}


void addBook(string book, string* books) {
	int p,q,mid,here;
		p = 0;
		q = books->length();
		while(p<q) {
			mid = (p+q)/2;
			if(books[p] < book && books[q] > book) { //edge case test
				throw "not found";
			}
			if(books[mid] < book) {
				p = mid; //if element greater than mid, make the mid the min
			}
			if(books[mid] > book) {
				q = mid; //if element less than mid, make the min the max
			}
			if(books[mid] == book) {
				here = mid; //return where book should be inserted found
			}
			}
	for(int i=0; i<book.size(); i++) {
		int j = i-1;

	while(j >= 0 && books[j] < books[here]) {
		books[j+1] = books[j]; //everything shifted over
		j--;
	}
	books[j+1] = book; //inserted
	}
}


// void addBooks(string* newbooks, string* books); // Uncomment to implement bonus
int main() {
	string* books = new string[MAXBOOKS];
	read("books.txt", books);
	string g;
	string e;
	string f;

	cout << "Which book would you like to find? " << endl;
	cin >> e;
	int found = exponentialSearch(books, e); //calls function to find e in books list
	cout << "The book is at " << found << endl;
	cout << "Which book would you add? " << endl;
	cin >> f;
	addBook(f, books);
	cout << f << " has been added successfully. " << endl;

/**************************************
 * TODO: Implement your code here:
 * 1. Take user input - search string
 * 2. Search for the book using exponentialSearch
 * 3. Take user input to add book to the list
 * 4. Add the book using addBook
 **************************************/
	delete [] books;
	return 0;
}
