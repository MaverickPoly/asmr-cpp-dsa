#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>

class point2d {
private:
    double x, y;
public:
    // Initializers
    point2d(double x = 0, double y = 0);

    double distance(const point2d& p) const;
    double get_x() const;
    double get_y() const;
    void set_x(double x);
    void set_y(double y);


    point2d operator+(const point2d& p) const;
    point2d operator-(const point2d& p) const;

    bool operator==(const point2d &point) const;
    bool operator!=(const point2d &point) const;

    friend std::ostream& operator<<(std::ostream& os, const point2d& p);
    friend std::ostream& operator<<(std::ostream& os, const point2d* p);

    ~point2d();
};


#endif
