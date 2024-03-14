#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "ArrayList.h"
#include "LinkedList.h"

struct HashTable{

    // You can declare more instance variables here
    int K;
    ArrayList<LinkedList<int>> arr;

    HashTable(){
        K = 10;
        // If you have more instance variables, init them here
        for (int i = 0; i < K; i++) {
            LinkedList<int> bucket;
            arr.append(bucket);
        }
    }

    HashTable(int K){
        this->K = K;
        // If you have more instance variables, init them here
        for (int i = 0; i < K; i++) {
            LinkedList<int> bucket;
            arr.append(bucket);
        }
    }

    void add(int value){
        // This function must be implemented
        int hash = hashFunction(value);
        arr[hash].append(value);
    }


    bool search(int value){
        // This function must be implemented
        int hash = hashFunction(value);
        return arr[hash].search(value);
    }

    // You can declare other functions if needed
    int hashFunction(int x) {
        int hash = x % K >= 0 ? x % K : (x % K) + K;
        return hash;
    }

};

#endif