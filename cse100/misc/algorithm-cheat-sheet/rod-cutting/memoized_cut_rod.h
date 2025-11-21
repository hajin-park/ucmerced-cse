#ifndef MEMOIZED_CUT_ROD_H
#define MEMOIZED_CUT_ROD_H

#include <limits>


int memoized_cut_rod_aux(int p[], int n, int r[]) {
    if (r[n] >= 0) {
        return r[n];
    }

    int q = std::numeric_limits<int>::min();

    if (n == 0) {
        q = 0;
    } else {
        for (int i = 1; i <= n; i++) {
            q = std::max(q, p[i-1] + memoized_cut_rod_aux(p, n-i, r));
        }
    }

    r[n] = q;
    return q;
}

int memoized_cut_rod(int p[], int n) {
    int* r = new int[n+1];
    
    for (int i = 0; i <= n; i++) {
        r[i] = std::numeric_limits<int>::min();
    }

    return memoized_cut_rod_aux(p, n, r);
}

#endif