#include <iostream>
#include "../Vector2/vector2.h"

#include "rect.h"

using namespace std;

int main() {
    rect r1;
    rect r2 (4, 5, 10, 9);
    rect r3 (0, 0, 10, 12);

    cout << "r1:" << r1 << endl;
    cout << "r1 perimeter:" << r1.perimeter() << endl;
    cout << "r1 area:" << r1.area() << endl << endl;

    cout << "r2:" << r2 << endl;
    cout << "r2 perimeter:" << r2.perimeter() << endl;
    cout << "r2 area:" << r2.area() << endl << endl;

    cout << "r3:" << r3 << endl;
    cout << "r3 perimeter:" << r3.perimeter() << endl;
    cout << "r3 area:" << r3.area() << endl << endl;

    if (r1 < r2) {
        cout << "r1 < r2" << endl;
    }
    if (r1 < r3) {
        cout << "r1 < r3" << endl;
    }
    if (r2 < r3) {
        cout << "r2 < r3" << endl;
    }
    if (r2 > r1) {
        cout << "r2 > r1" << endl;
    }
    r3 -= vector2{4, 8};
    cout << "r3:" << r3 << endl;
    if (r2 == r3) {
        cout << "r2 == r3" << endl;
    }

    cout << endl;
    cout << "Diagonal: " << r2.diagonal() << endl;
    cout << "TopLeft: " << r2.topLeft() << endl;
    cout << "TopRight: " << r2.topRight() << endl;
    cout << "BottomLeft: " << r2.bottomLeft() << endl;
    cout << "BottomRight: " << r2.bottomRight() << endl;
    cout << "Center: " << r2.center() << endl;
    cout << "Bottom: " << r2.bottom() << endl;
    cout << "Top: " << r2.top() << endl;
    cout << "Left: " << r2.left() << endl;
    cout << "Right: " << r2.right() << endl;

    return 0;
}
