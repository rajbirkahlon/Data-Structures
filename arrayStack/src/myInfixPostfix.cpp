/*
 * myInfixPostfix.cpp
 *
 *  Created on: Oct 15, 2018
 *      Author: Rajbi
 */

#include <iostream>
using namespace std;
#include "arrayStack.h"
#include <string>


bool precedence(char o1, char o2) { //checks whether character operator has higher or lower precedence than the top operator of stack
	if((o1=='*') && (o2=='/')) return true;
	if((o1=='*') && (o2=='+')) return true;
	if((o1=='*') && (o2=='-')) return true;
	if((o1=='/') && (o2=='+')) return true;
	if((o1=='/') && (o2=='-')) return true;
	if((o1=='+') && (o2=='-')) return true;
	else return false;
}

string convert(const string &s) {
	arrayStack<char> stack; //stack to store operators
	string post_s = ""; //string to be returned
	for(int i=0;i<s.length();i++) { //loops through string
		if(s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i] !='/' && s[i]!='(' && s[i]!=')')
					post_s = post_s+s[i]; //if char is just a letter, adds it to postfix string
		if(s[i]=='(')
			stack.push(s[i]);
		if(s[i]==')') {
			while(stack.top()!='(') { //puts operators within the parenteces on stack in postfix string
				post_s = post_s+stack.top();
				stack.pop();
			}
			stack.pop(); //removes '(' from stack
		}

		else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i] =='/') { //if character is operator
			if(stack.isEmpty()) { //can just push operator to stack if it's empty
				stack.push(s[i]);
			}

			if(!precedence(stack.top(),s[i]))
			stack.push(s[i]); //if lower precendence of top value of stack, just push

			else if(precedence(stack.top(),s[i])) { //checks if top value in stack has higher precedence and if it does...
					post_s = post_s + stack.top(); //adds top operator of stack to postfix string
					stack.pop(); //removes it from stack
					if(precedence(stack.top(),s[i])) {
						post_s = post_s + stack.top(); //adds top operator of stack to output string in case there were 2 higher precedence operators
						stack.pop(); //removes it from stack
					}
					stack.push(s[i]); //pushes operator to stack
			}
		}
	}
	for(int k=0;k<stack.stackSize();k++) { //after all of string is traversed, the remaining stack will be added to end of output string
		post_s = post_s+stack.top();
		stack.pop();
	}
	cout << post_s << endl; //outputs the postfix string
	return post_s;
}

int main() {
	arrayStack<int> stack;
	stack.isEmpty();
	stack.stackSize();
	stack.push(1);
	stack.push(4);
	stack.push(2);
	stack.push(99);
	stack.push(100);
	stack.push(2);
	stack.push(2);
	stack.push(2);
	stack.push(2);
	stack.print();
	stack.top();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.print();
	stack.top();
	stack.stackSize();
	stack.isEmpty();
	cout << endl;

	string in_s1 = "A+B-C";
	string in_s2 = "(A+B)*C";
	string in_s3 = "(A+B)*(C-D)";
	string in_s4 = "A+((B+C)*(E-F)-G)/(H-I)";
	string in_s5 = "A+B*(C+D)-E/F*G+H";
	convert(in_s1);
	convert(in_s2);
	convert(in_s3);
	convert(in_s4);
	convert(in_s5);
	return 0;
}
