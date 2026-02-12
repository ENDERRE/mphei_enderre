#include <iostream>

#ifndef LIB_ST
#define LIB_ST
#include "lab2_s.hpp"

namespace Geometry {
 int inputInt(const std::string& prompt);
    enum Axis { X_AXIS, Y_AXIS };

    struct Point {
        int x;
        int y;

        Point(int x_coord = 0, int y_coord = 0) : x(x_coord), y(y_coord) {}

        void input(const std::string& name) {
            x = inputInt("Введите x (" + name + "): ");
            y = inputInt("Введите y (" + name + "): ");
        }

        void print() const {
            std::cout << "(" << x << ", " << y << ")\n";
        }

        Point add(const Point& other) const {
            return Point(x + other.x, y + other.y);
        }

        void swap(Point& other) {
            std::swap(x, other.x);
            std::swap(y, other.y);
        }
    };

    struct Complex {
        int real;
        int imag;

        Complex(int r = 0, int i = 0) : real(r), imag(i) {}

        void input(const std::string& name) {
            real = inputInt("Введите действительную часть (" + name + "): ");
            imag = inputInt("Введите мнимую часть (" + name + "): ");
        }

        void print() const {
            if (imag >= 0)
                std::cout << real << " + " << imag << "i\n";
            else
                std::cout << real << " - " << -imag << "i\n";
        }

        Complex add(const Complex& other) const {
            return Complex(real + other.real, imag + other.imag);
        }

        void swap(Complex& other) {
            std::swap(real, other.real);
            std::swap(imag, other.imag);
        }
    };

   
}
#endif
