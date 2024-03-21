#include<stdio.h>

int bar(int a, int b, int c) {
    return (b - a) << (c);
}

int foo(int m, int n, int o) {
    int p = bar(m + o, n + o, m + n);
    int q = bar(m - o, n - m, n + n);
    printf("p + q: %d\n", p + q);
    return p + q;
}

int main() {
    int x = 2, y = 4, z = 6;
    z = x + y + z + foo(x, y, z);
    printf("%d\n", z);
    return 0;
}
