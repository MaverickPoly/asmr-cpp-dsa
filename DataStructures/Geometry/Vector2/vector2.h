#ifndef VECTOR2_H
#define VECTOR2_H

#include <iostream>

class vector2 {
public:
    double x, y;

    vector2();
    vector2(double x, double y);

    vector2& operator+=(const vector2& v);
    vector2& operator-=(const vector2& v);

    bool operator==(const vector2 &) const;
    bool operator!=(const vector2 &) const;

    friend std::ostream& operator<<(std::ostream& os, const vector2& v);
    friend std::ostream& operator<<(std::ostream& os, const vector2* v);
};


#endif
