#include <stdio.h> 

int main() {

    // Assign default values
    int x = 0;
    int y = 0;
    int *px, *py; 
    int arr[10] = {0};

    // Print the addresses of x and y
    printf("%p\n", &x);
    printf("%p\n", &y);

    // Assign the addresses of x and y to px and py
    px = &x;
    py = &y;

    // Print the values and addresses of px and py
    printf("%p\n", px);
    printf("%p\n", py);
    printf("%p\n", &px);
    printf("%p\n", &py);

    // Print the values of arr using pointer notation
    for (int i = 0; i < 10; i++) {  
        printf("%d\n", *(arr + i));
    }

    // Print and compare the addresses of arr[0] and arr
    printf("%p\n", &arr[0]);
    printf("%p\n", &arr);

    return 0; 
}