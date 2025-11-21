#include <iostream>
#include "ArrayList.h"
#include "TimeSupport.h"
#include "RandomSupport.h"

using namespace std;

int main() {

    const int N = 10000;
    RNG generator(1, N);

    ArrayList<int> hashmap;

    for (int i = 0; i < N; i++){
        hashmap.append(0);
    }
    
    timestamp start = current_time();

    for (int i = 0; i < N; i++){
        hashmap[generator.get()]++;

        for (int j = 0; j < N; j++){
            if (hashmap[N] > 0){
                ; 
            }
        }
    }

    timestamp end = current_time();

    int duration = time_diff(start, end);


    cout << "Took " << duration << " ms to complete" << endl;
    
    return 0;
}