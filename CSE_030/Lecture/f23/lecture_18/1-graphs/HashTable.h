#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <ArrayList.h>
#include <LinkedList.h>

template <class T>
struct HashTable{
private:
    HashTable(){
        K = 10;
        for(int i = 0; i < K; i++){
            storage.append(LinkedList<T>());
        }
    }
public:

    ArrayList<LinkedList<T>> storage;
    int K;
    int (*f)(T);

    HashTable(int K, int (*f)(T)){
        this->K = K;
        this->f = f;
        for(int i = 0; i < K; i++){
            storage.append(LinkedList<T>());
        }
    }

    int hash (T x){
        int ans = f(x);
        return ans;
    }

    void add(T value){
        int pos = hash(value);
        storage[pos].append(value);
    }


    bool search(T value){
        int pos = hash(value);
        return storage[pos].search(value);
    }


};

template <class T>
std::ostream& operator<<(std::ostream& os, const HashTable<T>& container){
    for (int i = 0; i < container.K; i++){
        os << i << ": " << container.storage.get(i) << std::endl;
    }

    return os;
}

#endif