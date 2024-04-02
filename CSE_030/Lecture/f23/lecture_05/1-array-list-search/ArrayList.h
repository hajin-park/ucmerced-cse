#ifndef ARRAY_LIST
#define ARRAY_LIST

#include <iostream>
#include <ostream>
#include <stdexcept>

template <class T>
class ArrayList;

template <class T>
std::ostream& operator<<(std::ostream& os, const ArrayList<T>& container);

template <class T>
class ArrayList{
protected:
    T* arr;
    int count;
    int capacity;

    void inflate(){
        if (count == capacity){
            int oldCapacity = capacity;
            capacity *= 2;

            T* temp = new T[capacity];

            for (int i = 0; i < oldCapacity; i++){
                temp[i] = arr[i];
            }

            T* old = arr;

            arr = temp;

            delete[] old;
        }
    }

public:
    ArrayList(){
        capacity = 1;
        arr = new T[capacity];
        count = 0;
    }

    ArrayList(const ArrayList& other){
        arr = new T[capacity];
        count = other.count;
        for (int i = 0; i < count; i++){
            arr[i] = other.arr[i];
        }
    }

    ArrayList& operator=(const ArrayList& other){
        count = other.count;
        for (int i = 0; i < count; i++){
            arr[i] = other.arr[i];
        }
        return *this;
    }

    T& operator[](int index){
        if (index < 0 || index >= count){
            throw std::logic_error("Array index out of bounds.");
        }
        return arr[index];
    }

    void append(T value){
        arr[count] = value;
        count++;

        inflate();
    }

    bool search (T value) const {
        for (int i = 0; i < count; i++){
            if (value == arr[i]){
                return true;
            }
        }
        return false;
    }

    int size() const {
        return count;
    }

    void stats() const{
        std::cout << "Count:     " << count << std::endl;
        std::cout << "Capacity:  " << capacity << std::endl;
        std::cout << std::endl;
    }

    ~ArrayList(){
        delete[] arr;
    }

    friend std::ostream& operator<< <>(std::ostream& os, const ArrayList<T>& container);
    friend struct TestArrayList;
};

template <class T>
std::ostream& operator<<(std::ostream& os, const ArrayList<T>& container){
    for (int i = 0; i < container.count; i++){
        os << container.arr[i];
        if (i < container.count-1){
            os << ", ";
        }
    }
    return os;
}

#endif