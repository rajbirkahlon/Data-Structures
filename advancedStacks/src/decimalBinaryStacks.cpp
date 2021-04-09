/*
 * decimalBinaryStacks.cpp
 *
 *  Created on: Oct 25, 2018
 *      Author: Rajbi
 */

#include <stack>
#include <iostream>
using namespace std;
#include <cmath>

int twoExponent(char i, int j) {
	if(i=='1'){
		int ret = pow(2, j);
		return ret;
	}
	else return 0;
}

string binaryDecConvert(const string &s) {
	string s_out = "";
	stack <int> stack;
	int j = 0;
	int k;
	int m = 0;
	//int out = 0;
	for(int i=0; i<s.length(); i++) {
		k = twoExponent(s[i],j);
		stack.push(k);
		j++;
	}

	while(!stack.empty()) {
		m = m+stack.top();
		stack.pop();
	}
	s_out = m;
	cout << m;
	return s_out;
}

int main() {
	string s1 = "1111";
	binaryDecConvert(s1);
	return 0;
}
