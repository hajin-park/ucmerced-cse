#include <iostream>
#include "TimeSupport.h"
#include "RandomSupport.h"

using namespace std;

// Linear search 
int linear_search(int value, int numbers[], int size){
    for (int i = 0; i < size; i++){
        if (numbers[i] == value){
            return i;
        }
    }

    return -1;
}

// Binary Search
int binary_search(int value, int numbers[], int size){
    int left = 0;
    int right = size - 1;

    while (left <= right){
        int mid = (left + right) / 2;

        if (numbers[mid] == value){
            return mid;
        }
        else{
            if (numbers[mid] > value){
                right = mid - 1;
            }
            else {
                // numbers[mid] < value
                left = mid + 1;
            }
        }
    }
    return -1;
}

// QuickSort
int partition(int arr[], int start, int end){
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quick_sort(int arr[], int start, int end){
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quick_sort(arr, start, p - 1);
 
    // Sorting the right part
    quick_sort(arr, p + 1, end);
}

// Insertion Sort
void insertion_sort(int arr[], int size)
{
    int i, key, j;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
 
        // Move elements of arr[0..i-1], 
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


int main(){
    // Read the list size and sorting algorithm from the user
    int N;
    cout << "Problem size: ";
    cin >> N;

    int algo;
    cout << "Sorting Algorithm ([1] Quick Sort, [2] Insertion Sort): ";
    cin >> algo;

    if (algo != 1 && algo != 2){
        cout << "Invalid selection" << endl;
        return 1;
    }

    // Declare an array of the appropriate size
    int arr[N];

    // Initialize a random number generator
    RNG rng(1, N);

    // Get the current time
    Timestamp start = current_time();

    // Fill the array with random numbers
    for (int i = 0; i < N; i++){
        arr[i] = rng.get();
        if (algo == 1){
            quick_sort(arr, 0, i);
        }
        else{
            insertion_sort(arr, i+1);
        }
        
        // Perform a search
        binary_search(-1, arr, i+1);
    }

    // Get the current time again
    Timestamp end = current_time();

    // The number of milliseconds that have elapsed between the 2 timestamps above
    int duration = time_diff(start, end);

    // Report the results
    cout << "Took " << duration << " ms. to complete on a collection of size " << N << endl;

    return 0;
}