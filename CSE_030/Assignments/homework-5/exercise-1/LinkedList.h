#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <ostream>
#include <stdexcept>

template <class T>
class LinkedList;

template <class T>
struct Link{
    T data;
    Link* next;
    Link* prev;

    Link(){
        data = 0;
        next = nullptr;
        prev = nullptr;
    }

    Link(T data){
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

template <class T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list){
    Link<T>* curr = list.front;
    while (curr != nullptr){
        os << curr->data;
        if (curr->next != nullptr) os << ", ";
        curr = curr->next;
    }

    return os;
}

template<class T>
class LinkedList{
protected:
    Link<T>* front;
    Link<T>* back;
    int count;
public:
    LinkedList(){
        front = nullptr;
        back = nullptr;
        count = 0;
    }
    
    void append(T value){
        if (front == nullptr){
            // Appending to an empty list
            front = new Link<T>(value);
            back = front;
        }
        else{
            // Appending to list with elements
            Link<T>* temp = new Link<T>(value);
            temp->prev = back;
            back->next = temp;
            back = temp;
        }
        count++;
    }

    void prepend(T value){
        if (front == nullptr){
            // Prepending to an empty list
            front = new Link<T>(value);
            back = front;
        }
        else{
            // Prepending to a list with elements
            Link<T>* temp = new Link<T>(value);
            temp->next = front;
            front->prev = temp;
            front = temp;
        }
        count++;
    }

    T removeFirst(){
        if (front == nullptr){
            throw std::logic_error("Can not remove from an empty list");
        }
        if (count == 1){
            T x = front->data;
            delete front;
            front = nullptr;
            back = nullptr;
            count--;
            return x;
        }
        else{
            T x = front->data;
            Link<T>* old = front;
            front = front->next;
            front->prev = nullptr;
            delete old;
            count--;
            return x;
        }
    }

    T peek() const {
        if (front == nullptr){
            throw std::logic_error("Can not peek into an empty list");
        }
        return front->data;
    }
    
    T removeLast(){
        // Your code goes here
        if (front == nullptr){
            throw std::logic_error("Can not remove from an empty list");
        }
        if (front == back){
            T x = front->data;
            delete front;
            front = nullptr;
            back = nullptr;
            count--;
            return x;
        } else{
            T x = back->data;
            Link<T>* old = back;
            back = back->prev;
            back->next = nullptr;
            delete old;
            count--;
            return x;
        } 
    } 

    int size() const {
        return count;
    }

    bool isEmpty() const {
        return count == 0;
    }

    void reverse(){
        Link<T>* oldFront = front;
        front = back;
        back = oldFront;

        Link<T>* curr = front;
        while(curr != nullptr){
            Link<T>* temp = curr->next;
            curr->next = curr->prev;
            curr->prev = temp;
            curr = curr->next;
        }
    }

    friend std::ostream& operator<<<>(std::ostream& os, const LinkedList& list);

    friend struct TestLinkedList;

};


#endif