#include <iostream>

using namespace std;

int Partition(int* arr, int p, int r) {
    int x = arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (arr[j] <= x) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

int RandomizedPartition(int* arr, int p, int r) {
    int i = rand() % (r - p + 1) + p;
    swap(arr[r], arr[i]);
    return Partition(arr, p, r);
}

void RandomizedQuickSort(int* arr, int p, int r) {
    if (p < r) {
        int q = RandomizedPartition(arr, p, r);
        RandomizedQuickSort(arr, p, q - 1);
        RandomizedQuickSort(arr, q + 1, r);
    }
}

void QuickSort(int* arr, int size) {
    RandomizedQuickSort(arr, 0, size - 1);
}

int main() {
    int size;
    cin >> size;
    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    QuickSort(arr, size);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << ";";
    }

    delete[] arr;

    return 0;
}