#ifndef EXTENDED_BOTTOM_UP_CUT_ROD_H
#define EXTENDED_BOTTOM_UP_CUT_ROD_H

#include <limits>
#include <iostream>

int** extended_bottom_up_cut_rod(int p[], int n) {
    int* r = new int[n+1];
    int* s = new int[n+1];
    int q;
    r[0] = 0;

    for (int j = 1; j <= n; j++) {
        q = std::numeric_limits<int>::min();

        for (int i = 1; i <= j; i++) {
            if (q < p[i-1] + r[j-i]) {
                q = p[i-1] + r[j-i];
                s[j] = i;
            }
        }

        r[j] = q;
    }

    int** f = new int*[2] {r, s};
    free(r);
    free(s);

    return f;
}

void print_cut_rod_solution(int p[], int n) {
    int** f = extended_bottom_up_cut_rod(p, n);

    std::cout << f[0][n] << '\n';
    while (n > 0) {
        std::cout << f[1][n] << " ";
        n = n - f[1][n];
    }

    free(f);
}

#endif