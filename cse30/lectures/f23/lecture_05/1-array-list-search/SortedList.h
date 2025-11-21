#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include "ArrayList.h"

template <typename T>
class SortedList : public ArrayList<T>{
public:
    void append(T value){
        this->arr[this->count] = value;
        this->count++;

        // Make sure it is in sorted position

        this->inflate();
    }

    bool search (T value) const {
        std::cout << "We will use Binary Search here" << std::endl;
        return false;
    }
};

#endif