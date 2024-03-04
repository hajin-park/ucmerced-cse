#include <stdio.h>
#include <ctype.h>


int main() {
    int ar[10], *p, *q, sum = 0;

    p = &ar[0]; q = &ar[10];
    while (p != q) {
        printf("%d\n", *p);
        sum += *p++;
        printf("%d\n", sum);
    }
}
