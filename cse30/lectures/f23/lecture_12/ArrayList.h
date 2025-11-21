// This file will contain part of your solution
#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <iostream>
#include <ostream>
#include <stdexcept>
template <class T>
struct ArrayList{
    T* data;
    int capacity;
    int count;

// Helper functions

    bool linear_search(const T& value){
        for (int i = 0; i < count; i++){
            if (data[i] == value){
                return true;
            }
        }
        return false;
    }

    bool binary_search(const T& value){
        int left = 0;
        int right = count;

        while (left <= right){
            int mid = (left + right) / 2;
            if (data[mid] == value){
                return true;
            }
            else if (data[mid] > value){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return false;
    }


    void selection_sort(){
        for (int i = 0; i < count; i++){
            T minVal = data[i];
            int minPos = i;
            for(int j = i; j < count; j++){
                if (data[j] < minVal){
                    minVal = data[j];
                    minPos = j;
                }
            }
            T temp = data[i];
            data[i] = data[minPos];
            data[minPos] = temp;
        }
    }

    void insertion_sort(){
        for (int i = 1; i < count; i++){
            int j = i;
            while (j > 0 && data[j-1] > data[j]){
                T temp = data[j];
                data[j] = data[j-1];
                data[j-1] = temp;
                j--;
            }
        }
    }


    // ================== START QUICKSORT ==================

    int partition(int start, int end){
        T pivot = data[start];

        int count = 0;
        for (int i = start+1; i <= end; i++){
            if (data[i] <= pivot){
                count++;
            }
        }

        int pivotIndex = start + count;

        T temp = data[start];
        data[start] = data[pivotIndex];
        data[pivotIndex] = temp;


        int left = start;
        int right = end;

        while (left < pivotIndex && right > pivotIndex){
            while(data[left] <= data[pivotIndex]){
                left++;
            }
            while (data[right] >= data[pivotIndex]){
                right--;
            }
            if (left < pivotIndex && right > pivotIndex){
                T temp = data[left];
                data[left] = data[right];
                data[right] = temp;
            }

        }
        return pivotIndex;
    }
 
    void quickSort(int start, int end) {
        if (start >= end)
            return;
    
        int p = partition(start, end);

        quickSort(start, p - 1);
    
        quickSort(p + 1, end);
    }

    void quick_sort(){
        quickSort(0, count - 1);
    }

    // =================== END QUICKSORT ===================
                    
public:
    ArrayList(){
        capacity = 1;
        count = 0;
        data = new T[capacity];
    }

    void append(T value){
        data[count] = value;
        count++;

        if (count == capacity){

            int oldCapacity = capacity;
            capacity *= 2;

            T* temp = new T[capacity];

            for (int i = 0; i < oldCapacity; i++){
                temp[i] = data[i];
            }

            T* oldLocation = data;
            data = temp;
            delete[] oldLocation;
        }
    }

    void add(T value){
        append(value);
        insertion_sort();
    }

    int size() const{
        return count;
    }

    T& operator[](int index){
        return data[index];
    }

    T& get(int index) const{
        return data[index];
    }

    bool search(const T& value){
        return linear_search(value);
    }

    void sort(){
        insertion_sort();
    }

    ~ArrayList(){
        delete[] data;
    }
};

template <class T>
std::ostream& operator<<(std::ostream& os, ArrayList<T>& list){
    for (int i = 0; i < list.size(); i++){
        os << list[i] << " ";
    }

    return os;
}

#endif