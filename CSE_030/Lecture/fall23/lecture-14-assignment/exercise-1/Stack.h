#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"
template <class T>
class Stack;

template <class T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& q);


template <class T>
class Stack{
    LinkedList<T> elements;
public:
    void push(T item){
        elements.prepend(item);
    }
    T pop(){
        return elements.removeFirst();
    }
    T peek() const{
        return elements.peek();
    }
    bool isEmpty() const {
        return elements.isEmpty();
    }
    int length() const {
        return elements.size();
    }
    friend std::ostream& operator<<<>(std::ostream& os, const Stack<T>& q);
};

template <class T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& q){
    os << q.elements;
    return os;
}

#endif