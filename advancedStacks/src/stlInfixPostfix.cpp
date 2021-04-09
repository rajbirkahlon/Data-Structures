/*
 * stlInfixPostfix.cpp
 *
 *  Created on: Oct 24, 2018
 *      Author: Rajbi
 */

#include <iostream>
using namespace std;
#include <stack>
#include <string>

bool precedence_checker(char o1, char o2) { //checks whether character operator has higher or lower precendence than the top operator of stack
	if(!o1 || !o2) 	   return true;
	if((o1=='*') && (o2=='/')) return true;
	if((o1=='*') && (o2=='+')) return true;
	if((o1=='*') && (o2=='-')) return true;
	if((o1=='/') && (o2=='+')) return true;
	if((o1=='/') && (o2=='-')) return true;
	if((o1=='+') && (o2=='-')) return true;
	else return false;
}

string convert_algorithm(const string &s) {
	//int length = 0;
	stack <char> o_stack; //stack to store operators
		string post_s = ""; //string to be returned
		for(int i=0;i<s.length();i++) { //loops through string
			if(s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i] !='/' && s[i]!='(' && s[i]!=')')
						post_s = post_s+s[i]; //if char is just a letter, adds it to postfix string
			if(s[i]=='(')
				o_stack.push(s[i]);
				//length++;
			if(s[i]==')') {
				while(o_stack.top()!='(') { //puts operators within the parenteces on stack in postfix string
					post_s = post_s+o_stack.top();
					o_stack.pop();
					//length--;
				}
				o_stack.pop(); //removes '(' from stack
				//length--;
			}

			else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i] =='/') { //if character is operator
				if(o_stack.empty()) { //can just push operator to stack if it's empty
					o_stack.push(s[i]);
					//length++;
				}

				else if(!precedence_checker(o_stack.top(),s[i])) {
					o_stack.push(s[i]);
					//length++; //if lower precendence of top value of stack, just push
				}

				else if(precedence_checker(o_stack.top(),s[i])) { //checks if top value in stack has higher precendence and if it does...
						post_s = post_s + o_stack.top(); //adds top operator of stack to postfix string
						o_stack.pop();
						//length--;//removes it from stack
						if(!o_stack.empty()) {
						if (precedence_checker(o_stack.top(),s[i])) {
							post_s = post_s + o_stack.top(); //adds top operator of stack to output string in case there were 2 higher precendence operators
							o_stack.pop();
							//length--;//removes it from stack
						}
						}
						o_stack.push(s[i]); //pushes operator to stack
						//length++;
				}
			}

		}
		for(int k=0;k<o_stack.size()+1;k++) { //after all of string is traversed, the remaining stack will be added to end of output string
			post_s = post_s+o_stack.top();
			o_stack.pop();
		}
		cout << post_s << endl; //outputs the postfix string
		return post_s;
}



string evaluatePostFix(string s) {
string s_out = "";
stack <char> num_Stack;
stack <int> ans_stack;
char n1;
int nn1;
char n2;
int nn2;
int n3;
//int nn3;

for(int i=0; i<s.length(); i++) {
	if(s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i] !='/' && s[i]!='(' && s[i]!=')') {
	num_Stack.push(s[i]);
	}
	else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i] =='/') {
		n1 = num_Stack.top();
		nn1 = n1;
		//nn1 = static_cast<int>(n1);
		num_Stack.pop();
		n2 = num_Stack.top();
		nn2 = n2;
		//nn2 = static_cast<int>(n2);
		num_Stack.pop();
		if(s[i] == '*') n3 = nn1*nn2;
		else if(s[i] == '+') n3 = nn1+nn2;
		else if(s[i] == '/') n3 = nn1/nn2;
		else if(s[i] == '-') n3 = nn1-nn2;
		num_Stack.push(n3);
	}
}
//s_out = s_out + num_Stack.top();
int out = num_Stack.top();
num_Stack.pop();
//int output = static_cast<int>(out);
cout << out << endl;
return s_out;
}

/*
int main() {
		string in_s1 = "A+B-C";
		string in_s2 = "(A+B)*C";
		string in_s3 = "(A+B)*(C-D)";
		string in_s4 = "A+((B+C)*(E-F)-G)/(H-I)";
		string in_s5 = "A+B*(C+D)-E/F*G+H";
		string in_s6 = "215*+";
		evaluatePostFix(in_s6);
		convert_algorithm(in_s1);
		convert_algorithm(in_s2);
		convert_algorithm(in_s3);
		convert_algorithm(in_s4);
		convert_algorithm(in_s5);
		//convert_algorithm(in_s6);
		return 0;
}
//*/
