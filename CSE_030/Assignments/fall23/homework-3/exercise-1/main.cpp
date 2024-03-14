#include <iostream>
#include "SortedList.h"

using namespace std;

int main(int argc, char* argv[]){
    // You can experiment with your data structure here...

    SortedList<int> nums;
    nums.append(5);
    nums.append(3);
    nums.append(9);
    nums.append(7);
    nums.append(1);
    nums.search(-1);
    nums.search(3);

    return 0;
}