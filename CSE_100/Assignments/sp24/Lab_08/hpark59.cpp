#include <iostream>
#include <limits>

using namespace std;


int** extended_bottom_up_cut_rod(int p[], int n) {
    int* r = new int[n+1];
    int* s = new int[n+1];
    int q;
    r[0] = 0;

    for (int j = 1; j <= n; j++) {
        q = numeric_limits<int>::min();

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
    cout << "TEST" << '\n';

    return f;
}

void print_cut_rod_solution(int p[], int n) {
    int** f = extended_bottom_up_cut_rod(p, n);

    cout << f[0][n] << '\n';
    while (n > 0) {
        cout << f[1][n] << " ";
        n = n - f[1][n];
    }
    cout << "-1";

    free(f);
}

int main(int argc, char** argv) {
    int n;
    cin >> n;
    int* p = new int[n + 1];
    p[0] = 0;
    for (int i = 1; i <= n; i++) {
      cin >> p[i];
    }

    print_cut_rod_solution(p, n);

    return 1;
}