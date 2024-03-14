#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <ostream>
#include <stdexcept>

template <class T>
class LinkedList;

template <class T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list);

template <class T>
struct Link{
    T data;
    Link* next;

    Link(){
        data = nullptr;
        next = nullptr;
    }

    Link(T data){
        this->data = data;
        next = nullptr;
    }
};

template <class T>
class LinkedList{
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
            back->next = temp;
            back = temp;
        }
        count++;
    }

    int& operator[](int index){
        if (index < 0 || index >= count){
            throw std::logic_error("Index out of bounds");
        }
        Link<T>* temp = front;
        for (int i = 0; i < index; i++){
            temp = temp->next;
        }
        return temp->data;
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
            front = temp;
        }
        count++;
    }

    T removeFirst() {
        if (front == nullptr){
            throw std::logic_error("LinkedList is empty.");
        }

        if (front->next == nullptr) {
            back = nullptr;
        }

        Link<T>* temp = front;
        T value = front->data;
        front = temp->next;
        delete temp;

        count--;
        return value;
    }

    T removeLast() {
        if (back == nullptr){
            throw std::logic_error("LinkedList is empty.");
        }

        Link<T>* temp = back;
        Link<T>* current = front;
        T value = back->data;

        if (count == 1) {
            front = nullptr;
            back = nullptr;
        } else {
            for (int i = 0; i < count-2; i++) {
                current = current->next;
            }
            back = current;
        }

        delete temp;
        count--;

        return value;
    }

    int size() {
        return count;
    }


    friend std::ostream& operator<< <T>(std::ostream& os, const LinkedList<T>& list);
    
    // The following 2 friend declarations must be present so the unit tests can run
    friend struct TestTemplates;
    friend struct TestRemoveMethods;

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


#endif