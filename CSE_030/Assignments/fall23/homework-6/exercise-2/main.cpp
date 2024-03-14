#include <iostream>
#include "LinkedList.h"
#include "TimeSupport.h"
#include "RandomSupport.h"
#include "ArrayList.h"
#include "HashTable.h"

using namespace std;



int main(){

    const int N = 10000;

    HashTable storage(N);
    RNG rng(1, N * 100);


    timestamp start = current_time();

    for (int i = 0; i < N; i++){
        int num = rng.get();
        storage.add(i);

        for (int j = 0; j < N; j++){
           storage.search(-1);
        }
    }

    timestamp end = current_time();

    int duration = time_diff(start, end);

    cout << "Took " << duration << " ms." << endl;

    return 0;
}