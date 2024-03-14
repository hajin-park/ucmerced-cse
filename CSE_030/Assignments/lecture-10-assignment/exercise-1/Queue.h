#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "LinkedList.h"

template <class T>
class Queue;

template <class T>
std::ostream& operator<<(std::ostream& os, const Queue<T>& q);

template <class T>
class Queue {
private:
    LinkedList<T> list;

public:
    void enqueue(const T& value) {
        list.append(value);
    }

    T dequeue() {
        return list.removeFirst();
    }

    T peek() const {
        return list.peek();
    }

    int size() const {
        return list.size();
    }

    bool isEmpty() const {
        return list.isEmpty();
    }

    int length() const {
        return list.size();
    }

    friend std::ostream& operator<<(std::ostream& os, const Queue& q) {
        os << q.list;
        return os;
    }
};

#endif
