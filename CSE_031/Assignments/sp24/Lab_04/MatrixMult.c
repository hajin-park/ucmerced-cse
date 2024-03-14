
#include <stdio.h>
#include <stdlib.h>

int** matMult(int **a, int **b, int size) {
	// (4) Implement your matrix multiplication here. 
	// You will need to create a new matrix to store the product.
	int **c = (int**) malloc(size * sizeof(int*));

	for (int i = 0; i < size; i++) {
		*(c+i) = (int*) malloc(size * sizeof(int));
		for (int j = 0; j < size; j++) {
			*(*(c+i)+j) = 0;
			for (int k = 0; k < size; k++) {
				*(*(c+i)+j) += *(*(a+i)+k) * (*(*(b+k)+j));
			}
		}
	}

	return c;
}

void printArray(int **arr, int n) {
	// (2) Implement your printArray function here
	for (int i = 0; i < n; i++) {
		printf("[ ");
		for (int j = 0; j < n; j++) {
			printf("%d ", *(*(arr+i)+j));
		}
		printf("]\n");
	}
}

int main() {
	int n = 5;
	int **matA, **matB, **matC;
	// (1) Define 2 (n x n) arrays (matrices). 
	matA = (int**) malloc(n * sizeof(int*));
	matB = (int**) malloc(n * sizeof(int*));

	for (int i = 0; i < n; i++) {
		*(matA+i) = (int*) malloc(n * sizeof(int));
		*(matB+i) = (int*) malloc(n * sizeof(int));
		for (int j = 0; j < n; j++) {
			*(*(matA+i)+j) = j+1;
			*(*(matB+i)+j) = j+1;
		}
	}

	// (3) Call printArray to print out the 2 arrays here.
	printArray(matA, n);
	printf("\n");
	printArray(matB, n);
	printf("\n");
	
	// (5) Call matMult to multiply the 2 arrays here.
	matC = matMult(matA, matB, n);
	
	// (6) Call printArray to print out resulting array here.
	printArray(matC, n);

    return 0;
}