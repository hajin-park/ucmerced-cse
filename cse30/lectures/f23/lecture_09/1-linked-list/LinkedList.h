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

class LinkedList{
    Link* front;
    Link* back;
    int count;
public:
    LinkedList(){
        front = nullptr;
        back = nullptr;
        count = 0;
    }

    // append

    void append(int value){
        if (front == nullptr){
            // Appending to an empty list
            front = new Link(value);
            back = front;
        }
        else{
            // Appending to list with elements
            Link* temp = new Link(value);
            back->next = temp;
            back = temp;
        }
        count++;
    }

    int& operator[](int index){
        if (index < 0 || index >= count){
            throw std::logic_error("Index out of bounds");
        }
        Link* temp = front;
        for (int i = 0; i < index; i++){
            temp = temp->next;
        }
        return temp->data;
    }

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
        count++;
    }

    int removeFirst(){
        if (front == nullptr){
            throw std::logic_error("Can not remove from an empty list");
        }
        if (count == 1){
            int x = front->data;
            delete front;
            front = nullptr;
            back = nullptr;
            count--;
            return x;
        }
        else{
            int x = front->data;
            Link* old = front;
            front = front->next;
            delete old;
            count--;
            return x;
        }
    }
    
    int removeLast(){
        return 0;
    } 

    friend std::ostream& operator<<(std::ostream& os, const LinkedList& list);

    friend struct TestLinkedList;

};

std::ostream& operator<<(std::ostream& os, const LinkedList& list){
    Link* curr = list.front;
    while (curr != nullptr){
        os << curr->data;
        if (curr->next != nullptr) os << ", ";
        curr = curr->next;
    }

    return os;
}


#endif