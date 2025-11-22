#ifndef stack_h
#define stack_h
#include "node.h"
#include <iostream> // Required for cout
using namespace std;  // Assumed from your other files

class Stack {
    NodePtr top;
    int size;
public:
    void push(int);
    int pop();
    bool isEmpty(); // Added helper function, useful for pop and Ex 2
    Stack();
    ~Stack();
};


void Stack::push(int x){
  NodePtr new_node = new NODE(x);
  if(new_node){ // Check if memory allocation was successful
        // New node's next pointer points to the current top
        new_node->set_next(top);
        // The stack's top pointer now points to the new node
        top = new_node;
        size++;
   } else {
       cout << "Error: Memory allocation failed." << endl;
   }
}

int Stack::pop(){
    if(isEmpty()){
        // cout << "Stack is empty. Cannot pop." << endl;
        return 0; // Return a default/null value for the parenthesis checker
    }
    
    NodePtr t = top;      // Temporary pointer to the top node
    int value;
    value = t->get_value(); // Get the value from the top node
    
    top = top->get_next(); // Move the stack's top pointer to the next node
    size--;
    
    delete t;      // Delete the original top node (this will print "deleting X")
    return value;
}

bool Stack::isEmpty(){
    return top == NULL; // Stack is empty if top is NULL
}

Stack::Stack(){
    //initialize stack
    top = NULL;
    size = 0;
}

Stack::~Stack(){
    //delete all remaning stack (i.e. pop all) 
    cout << "--- Deleting remaining stack nodes ---" << endl;
    NodePtr t = top;
    while(t != NULL){
        NodePtr next = t->get_next(); // Save the next node
        delete t;                     // Delete the current node (prints "deleting X")
        t = next;                     // Move to the next node
    }
    cout << "--- Stack deletion complete ---" << endl;
}


#endif