#include "vector2.h"

vector2::vector2() : x(0), y(0)
    { }
vector2::vector2(double x, double y) : x(x), y(y)
    { }


vector2& vector2::operator+=(const vector2 &v) {
    x += v.x;
    y += v.y;
    return *this;
}
vector2& vector2::operator-=(const vector2 &v) {
    x -= v.x;
    y -= v.y;
    return *this;
}


bool vector2::operator==(const vector2 &v) const {
    return x == v.x && y == v.y;
}
bool vector2::operator!=(const vector2 &v) const {
    return x != v.x || y != v.y;
}

std::ostream& operator<<(std::ostream &os, const vector2 &v) {
    return os << "vector2(" << v.x << ", " << v.y << ")";
}
std::ostream& operator<<(std::ostream &os, const vector2 *v) {
    return os << "vector2(" << v->x << ", " << v->y << ")";
}
