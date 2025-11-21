#include <iostream>
#include <ArrayList.h>
#include <TimeSupport.h>
#include <RandomSupport.h>

using namespace std;

int f(int x, int k){
    int r = x % k;
    if (r < 0){
        r += k;
    }
    return r;
}

int find_min(ArrayList<ArrayList<int>>& ht){
    int result = ht[0][0];
    for (int i = 0; i < ht.size(); i++){
        for (int j = 0; j < ht[i].size(); j++){
            if (ht[i][j] < result){
                result = ht[i][j];
            }
        }
    }
    return result;
}

int main(){

    int N = 1000000;
    int K = 100000;

    RNG generator(5, N*100);

    ArrayList<ArrayList<int>> ht;

    for (int i = 0; i < K; i++){
        ht.append(ArrayList<int>());
    }

    for (int i = 0; i < N; i++){
        int x = generator.get();
        int pos = f(x, K);

        ht[pos].append(x);
    }

    TimeStamp start;


    for(int i = 0; i < N; i++){
        int x = 4;
        int pos = f(x, K);
        ht[pos].search(x);
    }


    TimeStamp end;

    int duration = end - start;

    cout << "Took:   " << duration << " ms." << endl;

    return 0;
}