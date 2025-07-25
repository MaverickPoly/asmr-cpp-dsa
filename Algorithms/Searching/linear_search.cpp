#include <iostream>
#include <string>

using namespace std;

template <typename T>
int linear_search(T arr[], unsigned size, const T& target) {
    for (unsigned int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}


int main() {
    string languages[] = {"Uzbek", "Russian", "English", "Chinese", "Arabic", "Persian", "Spanish", "Turk", "French"};
    size_t len = size(languages);

    int index1 = linear_search<string>(languages, len, "Uzbek");
    int index2 = linear_search<string>(languages, len, "Chinese");
    int index3 = linear_search<string>(languages, len, "Persian");
    int index4 = linear_search<string>(languages, len, "Korean");

    cout << "Index 1: "<< index1 << endl;
    cout << "Index 2: "<< index2 << endl;
    cout << "Index 3: "<< index3 << endl;
    cout << "Index 4: "<< index4 << endl;

    return 0;
}
