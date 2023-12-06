#include "Square.hpp"
#include "Triangle.hpp"

Square::Square() : Figure{4} {};

Square::operator double() {
    Dot d[] = {dots[0], dots[1], dots[2]};
    Triangle t1(d);
    Dot d2[] = {dots[1], dots[2], dots[3]};
    Triangle t2(d2);

    double s;
    s = (double)t1 + (double)t2;

    return s;
};

Square::~Square() {};