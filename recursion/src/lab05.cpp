//============================================================================
// Name        : lab05.cpp
// Author      : Rajbir
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "arrayList.h"
using namespace std;

bool check_palindrome(const string &s) {
	if(s.length() <= 1) return true;
	if(s[0] != s[s.length()-1]) return false;
	else {
		string recurString = s.substr(1, s.length()-2);
		if(!check_palindrome(recurString)) return false;
	}
	return true;
}


int main() {
	string s = "madam";
	string s1 = "word";
	string s2 = "abcdedcba";

	if(check_palindrome(s))
		cout << "YES" << endl;
	else cout << "No" << endl;

	if(check_palindrome(s1))
			cout << "YES" << endl;
		else cout << "No" << endl;

	if(check_palindrome(s2))
			cout << "YES" << endl;
		else cout << "No" << endl;

	arrayList<int> list(7);
	list.insertAt(0,4); // 4
	list.insertAt(1,6); // 4 5
	list.insertAt(2,5); // 4 5 6
	list.insertAt(3,1);
	list.insertAt(4,3);
	list.insertAt(5,12);

	list.getMin();

	return 0;
}
