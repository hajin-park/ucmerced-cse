#include <stdio.h>

int main() {
	int i;
	int four_ints[4];
	char* four_c;

	for(i = 0; i < 4; i++)
        four_ints[i] = 2;

	printf("%x\n", four_ints[0]);
	
    four_c = (char*)four_ints;

	for(i = 0; i < 4; i++)
        four_c[i] = 'A' + i; // ASCII value of 'A' is 65 or 0x41 in Hex.
    
    // Add your code for the exercises here:

	printf("%x\n", four_ints[0]); // Exercise 3
	printf("%x\n", four_ints[1]); // Exercise 4

	printf("%p\n", four_ints); // Exercise 5c
	printf("%p\n", four_c); // Exercise 5c

	for (i = 0; i < (sizeof(four_ints)/sizeof(int)); i++) { // Exercise 6
		printf("%p\n", four_ints+i);
		printf("%X\n", four_ints[i]);
	}

	for (i = 0; i < 4; i++) { // Exercise 8
		printf("%p\n", four_c+i);
		printf("%X\n", four_c[i]);
	}

	return 0;
}