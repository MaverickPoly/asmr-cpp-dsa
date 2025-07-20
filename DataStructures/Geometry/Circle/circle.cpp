#include "circle.h"
#include <cmath>

#include "../Vector2/vector2.h"


circle::circle(point2d center, double radius) : center(center), radius(radius) { }

double circle::circumference() const {
    return 2 * M_PI * radius;
}
double circle::area() const {
    return M_PI * pow(radius, 2);
}


point2d circle::topLeft() const {
    return {center.get_x() - radius, center.get_y() + radius};
};
point2d circle::topRight() const {
    return {center.get_x() + radius, center.get_y() + radius};
};
point2d circle::bottomLeft() const {
    return {center.get_x() - radius, center.get_y() - radius};
};
point2d circle::bottomRight() const {
    return {center.get_x() + radius, center.get_y() - radius};
};
double circle::bottom() const {
    return center.get_y() - radius;
};
double circle::top() const {
    return center.get_y() + radius;
};
double circle::left() const {
    return center.get_x() - radius;
};
double circle::right() const {
    return center.get_x() + radius;
};

bool circle::operator==(const circle &other) const {
    return center == other.center && radius == other.radius;
}
bool circle::operator!=(const circle &other) const {
    return center != other.center || radius != other.radius;
}
circle &circle::operator+=(const vector2 v) {
    center.set_x(center.get_x() + v.x);
    center.set_y(center.get_y() + v.y);
    return *this;
}
circle &circle::operator-=(const vector2 v) {
    center.set_x(center.get_x() - v.x);
    center.set_y(center.get_y() - v.y);
    return *this;
}

bool circle::operator<(const circle &other) const {
    return area() < other.area();
}
bool circle::operator>(const circle &other) const {
    return area() > other.area();
}
bool circle::operator<=(const circle &other) const {
    return area() <= other.area();
}
bool circle::operator>=(const circle &other) const {
    return area() >= other.area();
}



std::ostream &operator<<(std::ostream &os, const circle &circle) {
    return os << "circle(center=" << circle.center << ", radius=" << circle.radius << ")";
}
std::ostream &operator<<(std::ostream &os, const circle *circle) {
    return os << "circle(center=" << circle->center << ", radius=" << circle->radius << ")";
}
