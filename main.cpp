#include<iostream>
#include <stdlib.h> // Required for atoi()
#include <string.h> // Required for strcmp()
using namespace std;

#include "stack.h"

int main(int argc, char **argv){
    Stack s;
     s.push(5);
     s.push(1);
     s.push(7);
     s.pop(); // Pops 7
     s.push(6);
     s.pop(); // Pops 6
     // Stack now contains: 1, 5 (from bottom up)

 /*
  Exercise 1*/
    cout << "\n--- Exercise 1: Processing argv ---" << endl;
    int i;
    for(i=1; i<argc; i++){
        // If argument is "x", pop the stack
        if(strcmp(argv[i], "x") == 0) {
            cout << "Popping value..." << endl;
            s.pop(); // The ~NODE() destructor will print "deleting [value]"
        }
        else { // Otherwise, push the argument as an integer
            int val = atoi(argv[i]);
            cout << "Pushing value: " << val << endl;
            s.push(val);
        }
    }
 
    cout << "\nMain finished. Destructor will be called automatically." << endl;
    return 0;
}