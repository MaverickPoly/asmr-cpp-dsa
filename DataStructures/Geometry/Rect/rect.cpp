#include "rect.h"
#include <cmath>

rect::rect(double x, double y, double width, double height) : x(x), y(y), width(width), height(height)
{}

double rect::perimeter() const {
    return 2 * (width + height);
}
double rect::area() const {
    return width * height;
}
double rect::diagonal() const {
    return sqrt(pow(width, 2) + pow(height, 2));
}

vector2 rect::topLeft() const {
    return vector2(x, y);
};
vector2 rect::topRight() const {
    return vector2(x + width, y);
};
vector2 rect::bottomLeft() const {
    return vector2(x, y - height);
};
vector2 rect::bottomRight() const {
    return vector2(x + width, y - height);
};
vector2 rect::center() const {
    return vector2((x + width) / 2, (y + height) / 2);
};
double rect::bottom() const {
    return y - height;
};
double rect::top() const {
    return y;
};
double rect::left() const {
    return x;
};
double rect::right() const {
    return x + width
    ;
};


bool rect::operator==(const rect &other) const {
    return x == other.x && y == other.y && width == other.width && height == other.height;
}
bool rect::operator!=(const rect &other) const {
    return x != other.x || y != other.y || width != other.width || height != other.height;
}
rect &rect::operator+=(vector2 v) {
    width += v.x;
    height += v.y;
    return *this;
}
rect &rect::operator-=(vector2 v) {
    width -= v.x;
    height -= v.y;
    return *this;
}


bool rect::operator<(const rect &other) const {
    return area() < other.area();
}
bool rect::operator>(const rect &other) const {
    return area() > other.area();
}
bool rect::operator>=(const rect &other) const {
    return area() >= other.area();
}
bool rect::operator<=(const rect &other) const {
    return area() <= other.area();
}



std::ostream &operator<<(std::ostream &os, const rect &rect) {
    return os << "Rect(x=" << rect.x << ", y=" << rect.y << ", width=" << rect.width << ", height=" << rect.height << ")";
}
std::ostream &operator<<(std::ostream &os, const rect *rect) {
    return os << "Rect(x=" << rect->x << ", y=" << rect->y << ", width=" << rect->width << ", height=" << rect->height << ")";
}
