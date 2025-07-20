#ifndef RECT_H
#define RECT_H


#include <iostream>

#include "../Vector2/vector2.h"


class rect {
public:
    double x, y, width, height;

    rect(double x = 0, double y = 0, double width = 0, double height = 0);

    double perimeter() const;
    double area() const;
    double diagonal() const;

    vector2 topLeft() const;
    vector2 topRight() const;
    vector2 bottomLeft() const;
    vector2 bottomRight() const;
    vector2 center() const;
    double bottom() const;
    double top() const;
    double left() const;
    double right() const;

    bool operator==(const rect& other) const;
    bool operator!=(const rect& other) const;
    rect& operator+=(vector2 v);
    rect& operator-=(vector2 v);

    bool operator<(const rect& other) const;
    bool operator>(const rect& other) const;
    bool operator<=(const rect& other) const;
    bool operator>=(const rect& other) const;

    friend std::ostream& operator<<(std::ostream& os, const rect& r);
    friend std::ostream& operator<<(std::ostream& os, const rect* r);
};



#endif //RECT_H
