#include <iostream>

using namespace std;

void bubble_sort(int *arr, unsigned size) {
    for (int i = 0; i < size; i++) {
        bool found = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                const int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                found = true;
            }
        }
        if (!found) return;
    }
}

int main() {
    int arr[] = {8, 3, 4, 9, 1, 7, 6, 5, 2, 0};

    bubble_sort(arr, size(arr));

    for (auto el : arr) cout << el << " ";

    return 0;
}
