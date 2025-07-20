#include <iostream>

#include "vector2.h"


using namespace std;

int main() {
    vector2 v1 {};
    vector2 v2 {4, 5};
    vector2 v3 {8, 6};

    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;
    cout << "v3: " << v3 << endl << endl;

    if (v1 == v2) {
        cout << "v1 == v2" << endl;
    }
    if (v3 == vector2{8, 6}) {
        cout << "v3 == vector2{8, 6}" << endl;
    }
    if (v2 != v3) {
        cout << "v2 != v3" << endl;
    }

    cout << endl;
    v1 += {4, 5};
    cout << v1 << endl;
    v1 -= {1, 3};
    cout << v1 << endl;


    return 0;
}