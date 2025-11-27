#include <iostream>
#include <cstdlib> // for atoi
#include <cstring> // for strcmp
#include "queue.h"

using namespace std;

int main(int argc, char **argv){
    Queue q;
    int i = 1;

    // Loop through command line arguments
    while(i < argc){
        if(strcmp(argv[i], "x") == 0){
            q.dequeue();
            i++;
        } else {
            // Assume input is always valid pairs: [Order_ID] [Quantity]
            if(i + 1 < argc){
                int order = atoi(argv[i]);
                int qty = atoi(argv[i+1]);
                
                q.enqueue(order, qty);
                cout << "My order is " << order << endl;
                
                i += 2; // Move past both the order number and quantity
            } else {
                // Edge case: number without quantity at the very end
                i++;
            }
        }
    }

    cout << "========================================" << endl;
    cout << "There are " << q.get_size() << " ppl left in the queue" << endl;

    return 0;
}