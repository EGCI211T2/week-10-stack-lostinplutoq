#ifndef queue_h
#define queue_h

#include "node.h"
#include <iostream>

using namespace std;

class Queue {
    NodePtr headPtr, tailPtr;
    int size;
    int customerNum; // Keeps track of customer number (1, 2, 3...)
public:
    void enqueue(int, int);
    void dequeue();
    int get_size();
    Queue();
    ~Queue();
};

Queue::Queue(){
    headPtr = NULL;
    tailPtr = NULL;
    size = 0;
    customerNum = 1;
}

void Queue::enqueue(int x, int y){
    NodePtr new_node = new NODE(x, y);
    if(new_node){
        if(size == 0){
            headPtr = new_node;
        } else {
            tailPtr->set_next(new_node);
        }
        tailPtr = new_node;
        size++;
    }
}

void Queue::dequeue(){
    if(headPtr == NULL) {
        // Rule 1: If the queue is empty, don't ask them to pay.
        cout << "The queue is empty." << endl;
        return;
    }

    NodePtr t = headPtr;
    int order = t->get_ord();
    int qty = t->get_qty();
    int price = 0;
    string foodName = "";

    // Pricing Logic
    switch(order){
        case 1: 
            foodName = "Ramen"; 
            price = 100 * qty; 
            break;
        case 2: 
            foodName = "Somtum"; 
            price = 20 * qty; 
            break;
        case 3: 
            foodName = "Fried Chicken"; 
            price = 50 * qty; 
            break;
        default: 
            foodName = "Unknown"; 
            price = 0; 
            break;
    }

    cout << "Customer no: " << customerNum << endl;
    cout << foodName << endl;
    cout << "You have to pay " << price << endl;

    // Payment Loop
    int cash = 0;
    while(true){
        cout << ":Cash:";
        cin >> cash;
        if(cash >= price) break;
        // If needed, you could print "Not enough" here, but the image implies just looping or re-entering.
    }

    cout << "Thank you" << endl;
    
    // Rule 2: If there is no change, you don't give change.
    int change = cash - price;
    if(change > 0){
        cout << "Change is:" << change << endl;
    }
    cout << "========================================" << endl; // Separator for next customer

    // Move head to next
    headPtr = headPtr->get_next();
    if(headPtr == NULL) tailPtr = NULL; // Update tail if queue becomes empty

    size--;
    customerNum++;
    delete t;
}

int Queue::get_size(){
    return size;
}

Queue::~Queue(){
    // Clean up remaining nodes
    NodePtr t = headPtr;
    while(t != NULL){
        NodePtr next = t->get_next();
        delete t;
        t = next;
    }
}

#endif