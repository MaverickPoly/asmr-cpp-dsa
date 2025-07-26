#include <cmath>
#include <iostream>

using namespace std;

class QuadraticEquation {
    double a, b, c;
public:

    QuadraticEquation(const double a, const double b, const double c) : a(a), b(b), c(c) {
        if (a == 0) {
            std::cerr << "Error: Invalid input!" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    void get_attributes(double& a, double& b, double& c) const {
        a = this->a;
        b = this->b;
        c = this->c;
    }

    double discriminant() const {
        return pow(b, 2) - 4 * a * c;
    }

    unsigned calculate_roots(double& x1, double& x2) const { // Returns number of roots
        const double D = discriminant();

        if (D < 0) return 0;
        if (D == 0) {
            x1 = - b / (2 * a);
            return 1;
        }
        x1 = (- b + sqrt(D)) / (2 * a);
        x2 = (- b - sqrt(D)) / (2 * a);
        return 2;
    }

    void calculate_vertex(double& x0, double& y0) const {
        x0 = - b / (2 * a);
        y0 = discriminant() / (4 * a);
    }
};

int main() {
    QuadraticEquation eq1 = QuadraticEquation(1, -4, 4);
    /*
     * -3 2
     * b = 1, c = -6
     */
    cout << eq1.discriminant() << endl;

    double a, b, c;
    eq1.get_attributes(a, b, c);
    cout << "Attributes: " << endl;
    cout << a << ' ' << b << ' ' << c << endl << endl;

    double x1, x2;
    eq1.calculate_roots(x1, x2);
    cout << "Roots: " << endl;
    cout << x1 << ' ' << x2 << endl << endl;

    double x0, y0;
    eq1.calculate_vertex(x0, y0);
    cout << "Vertex: " << endl;
    cout << x0 << ' ' << y0 << endl;

    return 0;
}
