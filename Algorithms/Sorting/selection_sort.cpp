#include <iostream>


using namespace std;


void selection_sort(int array[], unsigned size) {
    for (int i = 0; i < size; ++i) {
        unsigned min = i;
        for (int j = i + 1; j < size; ++j) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        // Swapping
        const int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

int main() {
    int array[] = {9, 8, 5, 4, 3, 7, 6, 0, 1, 2};

    selection_sort(array, size(array));

    for (int i = 0; i < size(array); i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}

