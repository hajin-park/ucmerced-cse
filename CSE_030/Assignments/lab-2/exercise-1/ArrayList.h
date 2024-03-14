#ifndef ARRAY_LIST
#define ARRAY_LIST

#include <iostream>
#include <ostream>
#include <stdexcept>

// Forward declaration of the class template ArrayList<T>.
// At this point the compiler knows there is something called ArrayList<T>
// A class template called ArrayList
// The compiler does not need to know exactly what ArrayList is at this point
// It just needs to know that there is something  like that.
// We need to do this because of the function template definition below,
// which needs to take in an argument of type ArrayList<T>. That's why 
// we had to pre-declare it here.
template <class T>
class ArrayList;


// This needs to be declared before the class ArrayList, so that it
// can be used inside the class to specify that we want it as a friend
// It takes in the class template ArrayList as a parameter,
// so it needs to be defined after the class declaration.
template <class T>
std::ostream& operator<<(std::ostream& os, const ArrayList<T>& container);


// Array list is a class template, allowing us to store data of any type
template <class T>
class ArrayList{
protected:
    T* arr;
    int count;
    int capacity;

    // Helper function to check if we are out of capacity,
    // in which case it doubles the capacity while preserving the data
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
    void deflate() {
        if (capacity > 1 && count < capacity/2) {
            capacity /= 2;
            T* temp = new T[capacity];

            for (int i = 0; i < count; i++){
                temp[i] = arr[i];
            }

            T* old = arr;
            arr = temp;
            delete[] old;
        }
    }

public:
    // Default constructor. Starts with capacity of 1. Will be increased if necessary.
    ArrayList(){
        capacity = 1;
        arr = new T[capacity];
        count = 0;
    }

    // Copy constructor. Needed because we store data on the heap
    ArrayList(const ArrayList& other){
        arr = new T[capacity];
        count = other.count;
        for (int i = 0; i < count; i++){
            arr[i] = other.arr[i];
        }
    }

    // Overloaded assignment operator. Needed because we store data on the heap
    ArrayList& operator=(const ArrayList& other){
        count = other.count;
        for (int i = 0; i < count; i++){
            arr[i] = other.arr[i];
        }
        return *this;
    }

    // This is so we are able to access and manipulate (read and write) any element in a valid position in the list
    T& operator[](int index){
        if (index < 0 || index >= count){
            throw std::logic_error("Array index out of bounds.");
        }
        return arr[index];
    }

    // Appends a value (to the end of the list)
    // We guarantee that there is always space to add one more
    // But after we have added that one, we may have run out of space
    // The inflate() function increases the capacity if necessary
    void append(T value){
        arr[count] = value;
        count++;

        inflate();
    }

    void prepend(T value){
        // Your code here...
        T* temp = new T[capacity];
        temp[0] = value;

        for (int i = 0; i < count; i++) {
            temp[i+1] = arr[i];
        }
        count++;
        T* old = arr;
        arr = temp;
        delete[] old;
        
        inflate();
    }

    T removeFirst() {
        // Your code here
        T* temp = new T[capacity];

        for (int i = 0; i < count - 1; i++) {
            temp[i] = arr[i+1];
        }

        count--;
        T* old = arr;
        arr = temp;
        delete[] old;

        deflate();
        return T();
    }

    T removeLast() {
        // Your code here
        T* temp = new T[capacity];

        for (int i = 0; i < count - 1; i++) {
            temp[i] = arr[i];
        }

        count--;
        T* old = arr;
        arr = temp;
        delete[] old;
        
        deflate();
        return T();
    }

    // Returns the number of elements in the list (not the overall capacity)
    int size() const {
        return count;
    }

    // This is for debugging purposes. Prints out the count and capacity
    void stats() const{
        std::cout << "Count:     " << count << std::endl;
        std::cout << "Capacity:  " << capacity << std::endl;
        std::cout << std::endl;
    }

    // Straightforward descructor
    ~ArrayList(){
        delete[] arr;
    }

    // Some friendship declarations here, for the overloaded operator<< 
    // and for Unit Testing purposes. We want the test program to have access to everything
    friend std::ostream& operator<< <>(std::ostream& os, const ArrayList<T>& container);
    friend struct TestArrayList;
};


// This is for being able to cout our ArrayList
// It is a function template because we wish to be able to pass a class template as a parameter
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