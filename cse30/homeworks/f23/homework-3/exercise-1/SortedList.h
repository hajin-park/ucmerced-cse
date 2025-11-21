#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include "ArrayList.h"

template <typename T>
class SortedList : public ArrayList<T> {
protected:
    void insertion_sort() {
        int j, key;
        for (int i = 1; i < this->count; i++) {
            key = this->arr[i];
            j = i - 1;

            while (j >= 0 && this->arr[j] > key) {
                this->arr[j+1] = this->arr[j];
                j -= 1;
            }
            this->arr[j + 1] = key;
        }
    }

    int binary_search(int value) const {
        int left = 0;
        int right = this->count - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (this->arr[mid] == value) { 
                return true;
            } else {
                if (this->arr[mid] > value) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        return false;
    }

public:
    void append(T value){
        // Your code here

        // Re-use binary search algorithm for a insertion-sorting algorithm
        // We can assume the current array before inserting a new item is sorted
        // The "mid" value from binary search becomes our "insertion index" value.
        int left = 0;
        int right = this->count;
        int insert_index = 0;
        
        while (left <= right) {
            insert_index = (left + right) / 2;

            if (this->arr[insert_index] == value) { 
                break;
            } else {
                if (this->arr[insert_index] > value) {
                    right = insert_index - 1;
                } else {
                    left = insert_index + 1;
                }
            }
        }

        // Move each item in the array one at a time
        // Each item moves up one spot, starting from the end.
        // Stop moving items at the insertion index, no need to move items behind it.
        for (int i = this->count; i > insert_index; i--) {
            this->arr[i] = this->arr[i-1];
        }
        this->arr[insert_index] = value;

        this->count++;
        this->inflate();
    }

    bool search(T value) {
        // Your code here
        return binary_search(value);
    }

    // This needs to be here because of the unit tests
    friend struct TestSortedList;

};

#endif