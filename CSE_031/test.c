#include <stdio.h>
#include <ctype.h>


int main() {
    int a[] = {10, 20, 30, 40, 50};
    int i = 0;
    a[i] = ++i;
    for  (i = 0; i < sizeof(a) / sizeof(int); i++)
    printf("%d\n", a[i]);
    return 0;
}

