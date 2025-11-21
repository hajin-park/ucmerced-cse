#include <iostream>
#include "LinkedList.h"
#include "TimeSupport.h"
#include "RandomSupport.h"

using namespace std;

int main(int argc, char* argv[]){

    const int N = 1000000;
    RNG rng(1, N*100);

    LinkedList nums;



    timestamp startAppend = current_time();

    for(int i = 0; i < N; i++){
        nums.append(rng.get());
    }

    timestamp endAppend = current_time();

    int appendDuration = time_diff(startAppend, endAppend);

    cout << "Took " << appendDuration << " ms. to append " << N << endl;



    timestamp startPrepend = current_time();

    for(int i = 0; i < N; i++){
        nums.removeFirst();
    }

    timestamp endPrepend = current_time();

    int durationPrepend = time_diff(startPrepend, endPrepend);

    cout << "Took " << durationPrepend << " ms. to remove " << N << endl;

    return 0;
}