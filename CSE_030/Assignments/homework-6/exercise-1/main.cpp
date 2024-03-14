#include <iostream>
#include "LinkedList.h"
#include "TimeSupport.h"
#include "RandomSupport.h"
#include "ArrayList.h"
#include "Container.h"

using namespace std;



int main(){

    const int N = 10000;

    Container arr(N);
    RNG rng(0, N-1);


    timestamp start = current_time();

    for (int i = 0; i < N; i++){
        int num = rng.get();
        arr.add(num);

        for (int j = 0; j < N; j++){
           arr.search(-1);
        }
    }

    timestamp end = current_time();

    int duration = time_diff(start, end);

    cout << "Took " << duration << " ms." << endl;

    return 0;
}