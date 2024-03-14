#include <stdio.h>
#include <stdlib.h>


int main() {
    int inputNum = 1;
    int inputCount = 1;
    int evenCount = 0;
    int oddCount = 0;
    int evenAvg = 0;
    int oddAvg = 0;
    int digitSum = 0;

    // Keep asking for numbers until 0 is entered
    while (inputNum != 0) {
        printf("Enter your %dst value: ", inputCount);
        scanf(" %d", &inputNum);

        if (inputNum == 0) {
            break;
        }

        // Calculate sum of digits
        int inputNumCopy = inputNum;
        while (inputNumCopy > 0) {
            digitSum += inputNumCopy % 10;
            inputNumCopy /= 10;
        }

        // Add to even or odd average total
        if (digitSum % 2 == 0) {
            evenAvg += digitSum;
            evenCount++;
        } else {
            oddAvg += digitSum;
            oddCount++;
        }

        inputCount++;
        digitSum = 0;
    }

    // Print out results
    if (inputCount == 1) {
        printf("There is no average to compute.");
    } else {
        if (evenAvg != 0) {
            printf("Average of input values whose digits sum up to an even number: %d\n", evenAvg/evenCount);
        }
        if (oddAvg != 0) {
            printf("Average of input values whose digits sum up to an odd number: %d\n", oddAvg/oddCount);
        }
    }
}