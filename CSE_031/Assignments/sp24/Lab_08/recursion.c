#include<stdio.h>

int recursion(int m) {
    if(m == -1) {
        printf("Returning 1\n");
        return 1;
    }
    else if(m == 0) {
        printf("Returning 3\n");
        return 3;
    }
    else
        return recursion(m - 2) + recursion(m - 1);
}

int main() {
    int x;
    printf("Please enter an integer: ");
	scanf("%d", &x);
    printf("%d\n", recursion(x));
    return 0;
}
