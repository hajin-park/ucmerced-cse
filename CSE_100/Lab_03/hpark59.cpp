#include <iostream>

using namespace std;

int maxCrossingSum(int arr[], int low, int mid, int high) {
    int leftSum = 0;
    int rightSum = 0;
    int sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
        }
    }
    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > rightSum) {
            rightSum = sum;
        }
    }
    return leftSum + rightSum;
}

int maxSubArraySum(int arr[], int size) {
    if (size == 1) {
        return arr[0];
    }
    int mid = size / 2;
    int leftSum = maxSubArraySum(arr, mid);
    int rightSum = maxSubArraySum(arr + mid, size - mid);
    int crossSum = maxCrossingSum(arr, 0, mid - 1, size - 1);
    return max(max(leftSum, rightSum), crossSum);
}

int main() {
    int size;
    cin >> size;
    int arr[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << maxSubArraySum(arr, size);
    
    return 0;
}