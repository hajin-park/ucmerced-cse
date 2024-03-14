#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"
template <class T>
class Stack;

template <class T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& q);

template <class T>
class Stack {
private:
    LinkedList<T> list;

public:
    void push(const T& value) {
        list.append(value);
    }

    T pop() {
        return list.removeLast();
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

    friend std::ostream& operator<<(std::ostream& os, const Stack& s) {
        os << s.list;
        return os;
    }
};

#endif
