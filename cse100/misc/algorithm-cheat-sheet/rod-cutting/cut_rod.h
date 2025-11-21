#ifndef CUT_ROD_H
#define CUT_ROD_H

#include <limits>


int cut_rod(int p[], int n) {
    if (n == 0) {
        return 0;
    }

    int q = std::numeric_limits<int>::min();
    for (int i = 1; i <= n; i++) {
        q = std::max(q, p[i-1] + cut_rod(p, n-i));
    }
    
    return q;
}

#endif