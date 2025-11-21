#ifndef ARRAY_LIST
#define ARRAY_LIST

#include <ostream>
#include <stdexcept>

template <class T>
class ArrayList{
    T* arr;
    int count;
    int capacity;
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

    int size() const {
        return count;
    }

    ~ArrayList(){
        delete[] arr;
    }
};

template <class T>
std::ostream& operator<<(std::ostream& os, ArrayList<T>& container){
    for (int i = 0; i < container.size(); i++){
        os << container[i];
        if (i < container.size()-1){
            os << ", ";
        }
    }
    return os;
}

#endif