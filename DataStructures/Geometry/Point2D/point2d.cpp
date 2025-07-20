#include "point2d.h"
#include <cmath>


point2d::point2d(double x, double y) : x(x), y(y)
    { }

double point2d::distance(const point2d &p) const {
    return sqrt(pow(p.x - x, 2) + pow(p.y - y, 2));
}
double point2d::get_x() const {return x;}
double point2d::get_y() const {return y;}
void point2d::set_x(double x) {this->x = x;}
void point2d::set_y(double y) {this->y = y;}

point2d point2d::operator+(const point2d &p) const {
    return {x + p.x, y + p.y};
}
point2d point2d::operator-(const point2d &p) const {
    return {x - p.x, y - p.y};
}

bool point2d::operator==(const point2d &point) const {
    return x == point.x && y == point.y;
}
bool point2d::operator!=(const point2d &point) const {
    return x != point.x || y != point.y;
}

std::ostream &operator<<(std::ostream &os, const point2d &p) {
    return os << "(" << p.x << ", " << p.y << ")";
}
std::ostream &operator<<(std::ostream &os, const point2d *p) {
    return os << "(" << p->x << ", " << p->y << ")";
}

point2d::~point2d() {
}
