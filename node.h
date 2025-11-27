#ifndef node_h
#define node_h

#include <iostream>
using namespace std;

class NODE{
    int ord_number, qty;
    NODE *nextPtr;
public:
    NODE(int, int);
    ~NODE();
    void set_next(NODE*);
    NODE* get_next();
    int get_ord();
    int get_qty();
};

typedef NODE* NodePtr;

// Constructor: Stores Order Number and Quantity
NODE::NODE(int o, int q){
    ord_number = o;
    qty = q;
    nextPtr = NULL;
}

// Getter: Get Order Number
int NODE::get_ord(){
    return ord_number;
}

// Getter: Get Quantity
int NODE::get_qty(){
    return qty;
}

// Getter: Get next node pointer
NODE* NODE::get_next(){
    return nextPtr;
}

// Setter: Set next node pointer
void NODE::set_next(NODE *t){
    nextPtr = t;
}

// Destructor
NODE::~NODE(){
    // Left empty to match the clean output of the image
    // cout << "deleting " << ord_number << endl; 
}

#endif