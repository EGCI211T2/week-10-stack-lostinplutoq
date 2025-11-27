#ifndef queue_h
#define queue_h
#include "node.h"
#include <iostream>

using namespace std;

class Queue {
    NodePtr headPtr;
    NodePtr tailPtr;
    int size;
public:
    void enqueue(int);
    int dequeue();
    bool isEmpty(); // เอาไว้เช็คว่ามีคนรอไหม
    int getSize();  // เอาไว้โชว์จำนวนคนเหลือตอนจบ
    Queue();
    ~Queue();
};

Queue::Queue(){
    headPtr = NULL;
    tailPtr = NULL;
    size = 0;
}

// เพิ่มข้อมูลเข้า "ท้ายแถว"
void Queue::enqueue(int x){
    NodePtr new_node = new NODE(x);
    if(new_node){
        if(size == 0){ // ถ้าคิวว่าง ให้ตัวใหม่เป็นหัวแถวด้วย
            headPtr = new_node;
        } else {
            tailPtr->set_next(new_node); // เอาตัวท้ายเก่า ชี้ไปตัวใหม่
        }
        tailPtr = new_node; // อัพเดทตัวท้ายเป็นตัวใหม่
        size++;
    } else {
        cout << "Memory allocation failed" << endl;
    }
}

// เอาข้อมูลออกจาก "หัวแถว"
int Queue::dequeue(){
    if(headPtr != NULL){
        NodePtr t = headPtr;
        int value = t->get_value();
        
        headPtr = headPtr->get_next(); // ขยับหัวแถวไปคนถัดไป
        if(headPtr == NULL) tailPtr = NULL; // ถ้าหมดแถวแล้ว ให้หางเป็น NULL ด้วย
        
        size--;
        delete t;
        return value;
    }
    return -1;
}

bool Queue::isEmpty(){
    return size == 0;
}

int Queue::getSize(){
    return size;
}

Queue::~Queue(){
    // cout << "Cleaning up queue..." << endl;
    while(headPtr != NULL){
        NodePtr temp = headPtr;
        headPtr = headPtr->get_next();
        delete temp;
    }
}

#endif