#include <iostream>

#include "point2d.h"

using namespace std;

int main() {
    point2d* p = new point2d{1, 2};
    point2d q {4, 6};

    cout << p->get_x() << " " << p->get_y() << endl;
    cout << "Distance:" << p->distance(q) << endl;
    cout << p << endl;

    cout << *p + point2d{5.0, 3.0} << endl;
    cout << *p - q << endl;

    bool eq = *p == q;
    cout << eq << endl;
    bool neq = point2d{4, 6} != q;
    cout << neq << endl;


    delete p;

    return 0;
}
