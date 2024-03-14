#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <chrono>
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

    LinkedList(const LinkedList<T>& other){
        front = nullptr;
        back = nullptr;
        count = 0;
        Link<T>* temp = other.front;
        while (temp != nullptr){
            append(temp->data);
            temp = temp->next;
        }
    }

    LinkedList<T>& operator=(LinkedList<T>& other){
        while (front != nullptr){
            Link<T>* old = front;
            front = front->next;
            delete old;
        }
        back = nullptr;
        count = 0;
        Link<T>* temp = other.front;
        while (temp != nullptr){
            append(temp->data);
            temp = temp->next;
        }
        
        return *this;
    }
    
    void append(T value){
        if (front == nullptr){
            front = new Link<T>(value);
            back = front;
        }
        else{
            Link<T>* temp = new Link<T>(value);
            temp->prev = back;
            back->next = temp;
            back = temp;
        }
        count++;
    }

    void prepend(T value){
        if (front == nullptr){
            front = new Link<T>(value);
            back = front;
        }
        else{
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

    T getFirst() const {
        if (front == nullptr){
            throw std::logic_error("Can not get element from an empty list");
        }
        return front->data;
    }

    T getLast() const {
        if (front == nullptr){
            throw std::logic_error("Can not get element from an empty list");
        }
        return back->data;
    }
    
    T removeLast(){
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

    bool search(T value){
        Link<T>* temp = front;

        while (temp != nullptr){
            if (temp->data == value){
                return true;
            }
        }

        return false;
    }

    ~LinkedList(){
        while (front != nullptr){
            Link<T>* old = front;
            front = front->next;
            delete old;
        }
    }

    friend std::ostream& operator<<<>(std::ostream& os, const LinkedList& list);

    friend struct TestLinkedList;

};




#endif