using namespace std;
#include <iostream>
#include "arrayQueue.h"

int main() {
	arrayQueue<int> A;
	//cout << A.isEmpty() << endl; //yes so 1
	//cout << A.size() << endl; //0
	A.enqueue(20);
	A.enqueue(30);
	//cout << A.front() << endl;//20
	//cout << A.size() << endl;//2
	A.print(); //20 30
	A.dequeue(); //20
	cout << A.size() << endl; //1
	A.print(); //30
	return 0;
}
