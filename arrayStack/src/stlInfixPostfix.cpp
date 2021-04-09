/*
 * stlInfixPostfix.cpp
 *
 *  Created on: Oct 17, 2018
 *      Author: Rajbi
 */

#include <iostream>
using namespace std;
#include <stack>
#include <string>

bool precedence_checker(char o1, char o2) { //checks whether character operator has higher or lower precendence than the top operator of stack
	//if((o1=='*' || o1=='/') && (o2=='+' || o2=='-')) return true;
	if((o1=='*') && (o2=='/')) return true;
	if((o1=='*') && (o2=='+')) return true;
	if((o1=='*') && (o2=='-')) return true;
	if((o1=='/') && (o2=='+')) return true;
	if((o1=='/') && (o2=='-')) return true;
	if((o1=='+') && (o2=='-')) return true;
	else return false;
}

string convert_algorithm(const string &s) {
	stack <char> o_stack; //stack to store operators
		string post_s = ""; //string to be returned
		for(int i=0;i<s.length();i++) { //loops through string
			if(s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i] !='/' && s[i]!='(' && s[i]!=')')
						post_s = post_s+s[i]; //if char is just a letter, adds it to postfix string
			if(s[i]=='(')
				o_stack.push(s[i]);
			if(s[i]==')') {
				while(o_stack.top()!='(') { //puts operators within the parenteces on stack in postfix string
					post_s = post_s+o_stack.top();
					o_stack.pop();
				}
				o_stack.pop(); //removes '(' from stack
			}

			else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i] =='/') { //if character is operator
				if(o_stack.empty()) { //can just push operator to stack if it's empty
					o_stack.push(s[i]);
				}

				if(!precedence_checker(o_stack.top(),s[i]))
				o_stack.push(s[i]); //if lower precendence of top value of stack, just push

				else if(precedence_checker(o_stack.top(),s[i])) { //checks if top value in stack has higher precendence and if it does...
						post_s = post_s + o_stack.top(); //adds top operator of stack to postfix string
						o_stack.pop(); //removes it from stack
						if(precedence_checker(o_stack.top(),s[i])) {
							post_s = post_s + o_stack.top(); //adds top operator of stack to output string in case there were 2 higher precendence operators
							o_stack.pop(); //removes it from stack
						}
						o_stack.push(s[i]); //pushes operator to stack
				}
			}
		}
		for(int k=0;k<o_stack.size();k++) { //after all of string is traversed, the remaining stack will be added to end of output string
			post_s = post_s+o_stack.top();
			o_stack.pop();
		}
		cout << post_s << endl; //outputs the postfix string
		return post_s;
}



