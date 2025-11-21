#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"
template <class T>
class Queue;

template <class T>
std::ostream& operator<<(std::ostream& os, const Queue<T>& q);


template <class T>
class Queue{
    LinkedList<T> elements;
public:
    void enqueue(T item){
        elements.append(item);
    }
    T dequeue(){
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

    friend std::ostream& operator<<<>(std::ostream& os, const Queue<T>& q);
};

template <class T>
std::ostream& operator<<(std::ostream& os, const Queue<T>& q){
    os << q.elements;
    return os;
}

#endif