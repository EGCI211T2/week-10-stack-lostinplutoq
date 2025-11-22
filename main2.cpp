#include<iostream>
#include <string.h> // Required for strlen()
using namespace std;

#include "stack.h"

int main(int argc, char **argv){
    Stack s;
   
/*
  Exercise 2
 */
    printf("Checking the parentheses in argv arguments\n");

    int i, j;
    // Loop for each argument string (starting from index 1)
    for(i=1; i<argc; i++){
        Stack s; // Create a new, empty stack for each argument
        bool balanced = true;

        cout << "Checking: " << argv[i] << endl;

        // Loop for each character in the current argument string
        for(j=0; j<strlen(argv[i]); j++){
            char c = argv[i][j];

            if(c == '{' || c == '[' || c == '('){
                // If it's an opening bracket, push it onto the stack
                s.push(c);
            }
            else if(c == '}'){
                // If it's a closing bracket, check for a match
                if(s.isEmpty() || s.pop() != '{'){
                    balanced = false;
                    break; // Mismatch found, stop checking this string
                }
            }
            else if(c == ']'){
                if(s.isEmpty() || s.pop() != '['){
                    balanced = false;
                    break;
                }
            }
            else if(c == ')'){
                if(s.isEmpty() || s.pop() != '('){
                    balanced = false;
                    break;
                }
            }
            // All other characters are ignored
        }
        
        // After checking all chars, the stack must be empty for it to be balanced
        if(!s.isEmpty()){
            balanced = false; // Catches cases like "{[" or "{{"
        }

        // Print the result for this argument
        cout << " -> " << argv[i] << " is ";
        if(balanced){
            cout << "BALANCED." << endl;
        } else {
            cout << "NOT BALANCED." << endl;
        }
        
        // Stack 's' goes out of scope here, and its destructor is called,
        // cleaning up any remaining nodes.
        cout << endl;
    }

   return 0;
}