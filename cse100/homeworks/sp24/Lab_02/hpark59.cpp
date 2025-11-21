#include <iostream>

using namespace std;

void Merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1 + 1];
    int R[n2 + 1];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[p + i];
    }

    for (int j = 0; j < n2; j++) {
        R[j] = arr[q + j + 1];
    }

    L[n1] = 1000000;
    R[n2] = 1000000;

    int i = 0;
    int j = 0;

    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
    }
}

void MergeSort(int arr[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        MergeSort(arr, p, q);
        MergeSort(arr, q + 1, r);
        Merge(arr, p, q, r);
    }
}

int main() {
    int count;

    cin >> count;
    
    int arr[count];

    for (size_t i = 0; i < count; i++)
    {
        cin >> arr[i];
    }
    
    MergeSort(arr, 0, count - 1);

    for (size_t i = 0; i < count; i++)
    {
        cout << arr[i] << ";";
    }

    return 0;
}