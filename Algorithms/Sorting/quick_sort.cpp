#include <iostream>

void swap(int& a, int& b) noexcept {
    const int temp = a;
    a = b;
    b = temp;
    // a = a ^ b;
    // b = a ^ b;
    // a = a ^ b;
}

unsigned partition(int* array, unsigned low, unsigned high) {
    int pivot = array[high];

    unsigned i = (low - 1);

    for (unsigned j = low; j <= high - 1; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }

    swap(array[i + 1], array[high]);
    return (i + 1);
}

void quick_sort(int* array, unsigned low, unsigned high) {
    if (low < high) {
        const unsigned w = partition(array, 0, high);

        quick_sort(array, low, w - 1);
        quick_sort(array, w + 1, high);
    }
}

int main() {
    int array[] = {0, 1, 9, 2, 8, 3, 7, 4, 6, 5};

    quick_sort(array, 0, std::size(array) - 1);

    for (int i = 0; i < std::size(array); ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}
