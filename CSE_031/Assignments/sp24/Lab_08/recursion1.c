
#include<stdio.h>

int recursion(int m) {
    if(m == -1) 
        return 3;
    else if(m <= -2) {
        if (m < -2)
            return 2; 
        else
            return 1;
    }
    else 
        return recursion(m - 3) + m + recursion(m - 2);
}

int main() {
    int x;
    printf("Please enter a number: ");
	scanf("%d", &x);
    printf("%d\n", recursion(x));
    return 0;
}
