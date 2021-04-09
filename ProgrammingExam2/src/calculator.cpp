#include <iostream>
#include "calculator.h"
#include <string>
using namespace std;
/**?
int main(){
try{
calculator c;
c.add(1);
c.add(14);
c.subtract(6);
c.add(4);
// Result is 13
cout << "Result: " << c.getResult() << endl;
c.undo(); // Expects 9
cout << "After undo: " << c.getResult() << endl;
c.undo(); // Expects 15
cout << "After undo: " << c.getResult() << endl;
c.redo(); // Expects 9
cout << "After redo: " << c.getResult() << endl;
c.redo(); // Expects 13
cout << "After redo: " << c.getResult() << endl;
//         c.redo(); // Uncommenting this statement should throw an error that no more redoes are possible
//         cout << "After redo: " << c.getResult() << endl;
c.undo(); // Expects 9
cout << "After undo: " << c.getResult() << endl;
c.printAllOperations(); //Prints all the operations from the beginning
// Expects Add 1. Add 14. Subtract 6. Add 4. Undo. Undo. Redo. Redo. Undo.
}
catch(const char* c){
cout << c << endl;
}
return 0;

} */
