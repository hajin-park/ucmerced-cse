#ifndef BOTTOM_UP_CUT_ROD_H
#define BOTTOM_UP_CUT_ROD_H

#include <limits>

int bottom_up_cut_rod(int p[], int n) {
    int* r = new int[n+1];
    int q;
    r[0] = 0;

    for (int j = 1; j <= n; j++) {
        q = std::numeric_limits<int>::min();

        for (int i = 1; i <= j; i++) {
            q = std::max(q, p[i-1] + r[j-i]);
        }

        r[j] = q;
    }

    int optimal_r = r[n];
    free(r);

    return optimal_r;
}


#endif