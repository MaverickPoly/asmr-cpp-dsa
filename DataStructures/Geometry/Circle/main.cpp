#include <iostream>

#include "circle.h"
#include "../Vector2/vector2.h"


using namespace std;

int main() {
    circle c1 {{5, 6}, 10};
    circle c2 {{0, 0}, 6};
    circle c3 {{14, 8}, 5};

    cout << "C1: " << c1 << endl;
    cout << "Circumference: " << c1.circumference() << endl;
    cout << "area: " << c1.area() << endl << endl;

    cout << "C2: " << c2 << endl;
    cout << "Circumference: " << c2.circumference() << endl;
    cout << "area: " << c2.area() << endl << endl;

    cout << "C3: " << c3 << endl;
    cout << "Circumference: " << c3.circumference() << endl;
    cout << "area: " << c3.area() << endl << endl;

    cout << "TopLeft: " << c3.topLeft() << endl;
    cout << "TopRight: " << c3.topRight() << endl;
    cout << "BottomLeft: " << c3.bottomLeft() << endl;
    cout << "BottomRight: " << c3.bottomRight() << endl;
    cout << "Bottom: " << c3.bottom() << endl;
    cout << "Top: " << c3.top() << endl;
    cout << "Left: " << c3.left() << endl;
    cout << "Right: " << c3.right() << endl;

    if (c1 == c2) {
        cout << "c1 == c2" << endl;
    }
    if (c1 != c3) {
        cout << "c1 != c3" << endl;
    }

    cout << endl << c1 << endl;
    c1 += vector2{4, 5};
    cout << c1 << endl;
    c1 -= vector2{3, 1};
    cout << c1 << endl;

    return 0;
}
