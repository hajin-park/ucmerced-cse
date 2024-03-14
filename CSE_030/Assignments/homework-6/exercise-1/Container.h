#ifndef CONTAINER_H
#define CONTAINER_H

#include "ArrayList.h"
#include "LinkedList.h"

struct Container{

    ArrayList<bool> storage;

    Container() {
        storage.append(false);
    }

    Container(int size) {
        for (int i = 0; i < size; i++) {
            storage.append(false);
        }
    }

    void add(int value){
        while (storage.size() <= value) {
            storage.append(false);
        }
        storage[value] = true;
    }

    bool search(int value){
        bool valueOutOfBounds = storage.size() < value;
        return valueOutOfBounds ? false : storage.get(value);
    }
};

#endif