#include<stdio.h>

int sub(int a) {
    int b = 2;
    return a - b;
}

int sum(int n) {
    int m = 15;
    return n + sub(m + n);
}

int main() {
    int x = 5, y = 10;

    y = y + x + sum(x);

    printf("%d\n", y);
    return 0;
}
