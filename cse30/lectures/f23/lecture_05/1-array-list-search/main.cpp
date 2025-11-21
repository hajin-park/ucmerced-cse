#include <iostream>
#include "SortedList.h"
#include "TimeSupport.h"
#include "RandomSupport.h"

using namespace std;

int main(int argc, char* argv[]){

    const int N = 10000;
    const int M = 100000;

    RNG rng(1, N);

    SortedList<int> numbers;

    numbers.append(5);

    cout << numbers.search(-1) << endl;

    // timestamp insertStart = current_time();

    // for (int i = 0; i < N; i++){
    //     int value = rng.get();
    //     numbers.append(value);
    // }

    // timestamp insertEnd = current_time();

    // int insertDuration = time_diff(insertStart, insertEnd);
    // cout << "Took " << insertDuration << " ms. to insert " << N << " values" << endl;



    // timestamp searchStart = current_time();

    // for (int i = 0; i < M; i++){
    //     numbers.search(-1);
    // }

    // timestamp searchEnd = current_time();

    // int searchDuration = time_diff(searchStart, searchEnd);
    // cout << "Took " << searchDuration << " ms. to perform " << M << " searches" << endl;

    
    return 0;
}