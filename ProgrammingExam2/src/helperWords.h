/*
 * helperWords.h
 *
 *  Created on: Oct 30, 2018
 *      Author: Rajbi
 */

#ifndef HELPERWORDS_H_
#define HELPERWORDS_H_

#include <string>
using namespace std;

string extractFirstWord(string s, string delim){
	unsigned int pos = s.find(delim);
	if(pos == string::npos)
		return s;
	else
		return s.substr(0, pos);
	//s.erase(0, pos + 1);
	//extractFirstWord(s, delim);
}


#endif /* HELPERWORDS_H_ */
