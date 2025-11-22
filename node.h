//
//  node.h
//
#ifndef node_h
#define node_h

#include <iostream>
using namespace std;

class NODE{
     int data;
    NODE *nextPtr;
public:
    NODE(int);
    ~NODE();
    void set_next(NODE*);
    NODE* get_next();
    int get_value();
};

typedef NODE* NodePtr;

// Constructor
NODE::NODE(int x){
    data = x;
    nextPtr = NULL;
}

// Getter: Get next node pointer
NODE* NODE::get_next(){
    return nextPtr;
}

// Getter: Get data value
int NODE::get_value(){
    return data;
}

// Setter: Set next node pointer
void NODE::set_next(NODE *t){
     nextPtr = t;
}

// Destructor
NODE::~NODE(){
     cout << "deleting " << data << endl;
}

#endif