#include <iostream>
#include "cut_rod.h"
#include "memoized_cut_rod.h"
#include "bottom_up_cut_rod.h"
#include "extended_bottom_up_cut_rod.h"

using namespace std;

int main() {
    int n = 4;
    int p[] {1, 5, 8, 9};

    cout << cut_rod(p, n) << endl;
    cout << memoized_cut_rod(p, n) << endl;
    cout << bottom_up_cut_rod(p, n) << endl;
    print_cut_rod_solution(p, n);
}