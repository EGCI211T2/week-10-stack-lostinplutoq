#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

using namespace std;

int main(int argc, char **argv) {
    Queue q;
    int customerNo = 1;

    // Loop through arguments
    for(int i = 1; i < argc; i++) {
        
        // If argument is "x", process the customer (Dequeue)
        if(strcmp(argv[i], "x") == 0) {
            
            // Requirement 1: If queue is empty, don't ask to pay.
            if(!q.isEmpty()) {
                cout << "Customer no: " << customerNo << endl;
                
                // We assume data is stored as: [Food ID] -> [Quantity]
                int order = q.dequeue();
                int qty = q.dequeue(); 
                
                int pricePerUnit = 0;
                string menuName = "";

                // Determine Menu and Price
                switch(order) {
                    case 1: 
                        menuName = "Ramen"; 
                        pricePerUnit = 100; 
                        break;
                    case 2: 
                        menuName = "Somtum"; 
                        pricePerUnit = 20; 
                        break;
                    case 3: 
                        menuName = "Fried Chicken"; 
                        pricePerUnit = 50; 
                        break;
                    default: 
                        menuName = "Unknown"; 
                        break;
                }

                int totalPrice = pricePerUnit * qty;
                cout << menuName << endl;
                cout << "You have to pay " << totalPrice << endl;

                // Payment Loop
                int cash = 0;
                cout << ":Cash:"; // First prompt has a colon
                cin >> cash;
                
                // Keep asking if cash is insufficient
                while(cash < totalPrice) {
                    cout << "Cash:"; // Subsequent prompts (match screenshot style)
                    cin >> cash;
                }

                cout << "Thank you" << endl;

                // Requirement 2: If no change, don't print "Change is..."
                int change = cash - totalPrice;
                if(change > 0) {
                    cout << "Change is:" << change << endl;
                }
                
                cout << "========================================" << endl;
                customerNo++;
            }
            // If queue is empty, we do nothing (per requirement)

        } else {
            // It's a number (Order ID)
            int orderID = atoi(argv[i]);
            
            // Assume the format is always ID followed by QTY
            // We enqueue both logic items
            if(i + 1 < argc && strcmp(argv[i+1], "x") != 0) {
                int qty = atoi(argv[i+1]);
                q.enqueue(orderID);
                q.enqueue(qty);
                cout << "My order is " << orderID << endl;
                i++; // Skip the next argument because it was the quantity
            }
        }
    }

    // Since we store 2 nodes per person (Order + Qty), divide size by 2
    cout << "There are " << q.getSize() / 2 << " ppl left in the queue" << endl;
    return 0;
}