#include <iostream>
#include <Vector>

using namespace std;

int main(int argc, char *argv[]) {
    int size, key, tracker, temp;
    vector<int> arr;

    // Initialize input values
    cin >> size;
    for (int i = 0; i < size; i++) {
        cin >> temp;
        arr.push_back(temp);
    }

    // Edge cases if arr size is 1 or empty
    if (size == 0) {
        return 0;
    } else if (size == 1) {
        cout << arr[0] << ";" << endl;
        return 0;
    }

    // Insertation sort
    for (int i = 1; i < size; i++) {
        key = arr[i];
        tracker = i - 1;

        while (tracker >= 0 && arr[tracker] > key) {
            arr[tracker + 1] = arr[tracker];
            tracker = tracker - 1;
        }
        arr[tracker + 1] = key;

        // Print each iteration of insertation sort
        for (int j = 0; j < i + 1; j++) {
            cout << arr[j] << ";";
        }
        cout << endl;
    }
}