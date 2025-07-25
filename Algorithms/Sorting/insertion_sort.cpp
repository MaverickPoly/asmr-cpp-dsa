#include <iostream>

using namespace std;


void insertion_sort(int array[], unsigned size) {
    for (int i = 1; i < size; ++i) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}


int main() {
    int array[] = {8, 9, 0, 5, 6, 7, 2, 3, 4, 1};

    insertion_sort(array, size(array));

    for (int i = 0; i < size(array); i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
