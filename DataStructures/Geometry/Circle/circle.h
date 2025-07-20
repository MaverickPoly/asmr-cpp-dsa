#ifndef CIRCLE_H
#define CIRCLE_H
#include "../Point2D/point2d.h"


class vector2;

class circle {
public:
    point2d center;
    double radius;

    circle(point2d center, double radius);

    double circumference() const;
    double area() const;

    point2d topLeft() const;
    point2d topRight() const;
    point2d bottomLeft() const;
    point2d bottomRight() const;
    double bottom() const;
    double top() const;
    double left() const;
    double right() const;

    bool operator==(const circle& other) const;
    bool operator!=(const circle& other) const;
    circle& operator+=(const vector2 v);
    circle& operator-=(const vector2 v);

    bool operator<(const circle& other) const;
    bool operator>(const circle& other) const;
    bool operator<=(const circle& other) const;
    bool operator>=(const circle& other) const;

    friend std::ostream& operator<<(std::ostream& os, const circle& r);
    friend std::ostream& operator<<(std::ostream& os, const circle* r);
};


#endif