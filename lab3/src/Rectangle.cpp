#include "Rectangle.hpp"
#include "Triangle.hpp"

Rectangle::Rectangle() : Figure(4) {};

Rectangle::~Rectangle() {};

Rectangle::operator double() {
    Dot d[] = {dots[0], dots[1], dots[2]};
    Triangle t1(d);
    Dot d2[] = {dots[0], dots[1], dots[2]};
    Triangle t2(d2);

    double s;
    s = (double)t1 + (double)t2;

    return s;
};

