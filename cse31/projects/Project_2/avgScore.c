#include <stdio.h>
#include <stdlib.h>

int orig[25], sorted[25];

// Print contents of arr in a single line
void printArray(int *arr, int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selSort(int len) {
    int i, j, temp;
    for (int i = 0; i < len; ++i) {
        sorted[i] = orig[i];
    }
    
    for (i = 0; i < len - 1; i++) {
        // Find the max element in sorted[i..len-1].
        int maxIndex = i;                   // Assume 1st element in sorted[i..len-1] is the max.
        for (j = i + 1; j < len; j++) {     // Test against elements after i to find the largest.
            if (sorted[j] > sorted[maxIndex]) {   // If this element is bigger, then it is the new max.
                maxIndex = j;               // Found new max. Remember its index.
            }
        }
        // Swap max element in sorted[i..len-1] and with the first element in sorted[i..len-1].
        temp = sorted[maxIndex];
        sorted[maxIndex] = sorted[i];
        sorted[i] = temp;
    }
}

// Recursive summation of arr[0..len - 1]
int calcSum(int *arr, int len)
{
    if (len <= 0)
        return 0;
    return (calcSum(arr, len - 1) + arr[len - 1]);
}

int main() {
    int i, numScores, drop;
    printf("Enter the number of assignments (between 1 and 25): ");
    scanf("%d", &numScores);
    for (i = 0; i < numScores; ++i) {
        printf("Enter score: ");
        scanf("%d", &orig[i]);
    }
    selSort(numScores);
    printf("Original scores: ");
    printArray(orig, numScores);
    printf("Sorted scores (in descending order): ");
    printArray(sorted, numScores);
    printf("Enter the number of (lowest) scores to drop: ");
    scanf("%d", &drop);
    printf("Average (rounded down) with dropped scores removed: %d\n", calcSum(sorted, numScores - drop)/(numScores - drop));
    return 0;
}