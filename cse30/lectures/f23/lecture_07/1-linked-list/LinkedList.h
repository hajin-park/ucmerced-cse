#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <ostream>
#include <stdexcept>
struct Link{
    int data;
    Link* next;

    Link(){
        data = 0;
        next = nullptr;
    }

    Link(int data){
        this->data = data;
        next = nullptr;
    }
};

// bool search(Link* start, int value){
//     Link* curr = start;
//     while(curr != nullptr){
//         if (curr->data == value){
//             return true;
//         }
//         curr = curr->next;
//     }
//     return false;
// }

class LinkedList{
    Link* front;
    Link* back;

public:
    LinkedList(){
        front = nullptr;
        back = nullptr;
    }

    // append


    // prepend

    void prepend(int value){
        if (front == nullptr){
            // Prepending to an empty list
            front = new Link(value);
            back = front;
        }
        else{
            // Prepending to a list with elements
            Link* temp = new Link(value);
            temp->next = front;
            front = temp;
        }
    }


    // search

};

// cout

#endif