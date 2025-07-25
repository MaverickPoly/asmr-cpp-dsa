#include <iostream>

using namespace std;

#define SIZE 101


int binary_search(const int arr[], const int len, const int& target) {
    int low = 0; int high = len - 1;
    // 5, 6, 7, 8, 9, 10, 11
    while (low < high) {
        const int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] > target) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return -1;
}

int main() {
    int array[SIZE];

    for (int i = 0; i < SIZE; i++) {
        array[i] = i + 10;
    }

    for (int i = 0; i < SIZE; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    int index1 = binary_search(array, SIZE, 50);
    int index2 = binary_search(array, SIZE, 73);
    int index3 = binary_search(array, SIZE, 98);
    int index4 = binary_search(array, SIZE, 0);

    cout << "Index 1: " << index1 << endl;
    cout << "Index 2: " << index2 << endl;
    cout << "Index 3: " << index3 << endl;
    cout << "Index 4: " << index4 << endl;

    return 0;
}
