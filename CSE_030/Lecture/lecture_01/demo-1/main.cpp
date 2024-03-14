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

int main(){
    // Read the list size and number of searches from the user
    int N;
    int M;
    cout << "Problem size: ";
    cin >> N;

    cout << "Number of searches: ";
    cin >> M;

    // Declare an array of the appropriate size
    int arr[N];

    // Initialize a random number generator
    RNG rng(1, N);

    // Fill the array with random numbers
    for (int i = 0; i < N; i++){
        arr[i] = rng.get();
    }

    // Get the current time
    Timestamp start = current_time();

    // Perform the specified number of searches
    for (int i = 0; i < M; i++){
        linear_search(-1, arr, N);
    }

    // Get the current time again
    Timestamp end = current_time();

    // The number of milliseconds that have elapsed between the 2 timestamps above
    int duration = time_diff(start, end);

    // Report the results
    cout << "Took " << duration << " ms. to complete " << M << " searches on a collection of size " << N << endl;

    return 0;
}