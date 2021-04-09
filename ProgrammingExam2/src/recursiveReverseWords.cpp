//============================================================================
// Name        : ProgrammingExam2.cpp
// Author      : Rajbir
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include "helperWords.h"
using namespace std;


string reverseWords(string input) {
	/*
	string s1,s2,s3,s4,s5,s6,s7,s8,s9;
	//int input_size = input.size();
	s1 = extractFirstWord(input,"");
	string s1r = input.substr(s1.size(),input.size());
	//input.resize(input.size()-(s1.size()+1));
	s2 = extractFirstWord(s1r," ");
	string s2r =input.substr(s2.size(),input.size());
	//input.resize(input.size()-(s1.size()+s2.size()));
	s3 = extractFirstWord(s2r," ");
	string s3r =input.substr(s3.size(),input.size());
	//input.resize(input.size()-s2.size());
	s4 = extractFirstWord(s3r," ");
	string s4r =input.substr(s4.size(),input.size());
	s5 = extractFirstWord(s4r," ");
	string s5r =input.substr(s5.size(),input.size());
	s6 = extractFirstWord(s5r," ");
	string s6r =input.substr(s6.size(),input.size());
	s7 = extractFirstWord(s6r," ");
	string s7r =input.substr(s7.size(),input.size());
	s8 = extractFirstWord(s7r," ");
	string s8r =input.substr(s8.size(),input.size());
	s9 = extractFirstWord(s8r," ");
	//string s2r =input.substr(s2.size()+1,input.size());

	string output = " ";
	output = output + s9 + s8 + s7 + s6 + s5 + s4 + s3 + s2 + s1;
	return output; */
	string s_out = " ";
	string s1 = " ";
	string s2 = " ";
	string s3 = " ";
	string s4 = " ";
	string s5 = " ";
	string s6 = " ";
	string s7 = " ";
	string s8 = " ";
	string s9 = " ";

	for(int i = 0; i<input.size(); i++) {
				while(!isspace(input[i]) && input[i]){
				s1 = s1 + input[i]; // first word put into a string
				i++; //skips over ws
				}
				i++;

				while(!isspace(input[i]) && input[i]){
				s2 = s2 + input[i]; // first word put into a string
				i++; //skips over ws
				}
				i++;

				while(!isspace(input[i]) && input[i]) {
				s3 = s3 + input[i];
				i++;
				}
				i++;

				while(!isspace(input[i]) && input[i]) {
				s4 = s4 + input[i];
				i++;
				}
				i++;

				while(!isspace(input[i]) && input[i]) {
				s5 = s5 + input[i];
				i++;
				}
				i++;

				while(!isspace(input[i]) && input[i]) {
				s6 = s6 + input[i];
				i++;
				}
				i++;

				while(!isspace(input[i]) && input[i]) {
				s7 = s7 + input[i];
				i++;
				}
				i++;

				while(!isspace(input[i]) && input[i]) {
				s8 = s8+input[i];
				i++;
				}
				i++;

				while(!isspace(input[i]) && input[i]) {
					s9 = s9+input[i];
					i++;
				}
				i++;
	}
	//s_out = s_out+s9+s8+s7+s6+s5+s4+s3+s2+s1;
	return s9+s8+s7+s6+s5+s4+s3+s2+s1;
}



int main() {
string s;

s = reverseWords("A quick brown fox jumps over the lazy dog");
cout << s << endl; // Expects dog lazy the over jumps fox brown quick A

s = reverseWords("Tuesday");
cout << s << endl; // Expects Tuesday

s = reverseWords("Algorithms and Data Structure Design");
cout << s << endl; // Expects Design Structure Data and Algorithms

return 0;
}
