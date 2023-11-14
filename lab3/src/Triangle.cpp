#include "Triangle.hpp"
#include <cmath>

Triangle::Triangle() : Figure(3) {};

Triangle::Triangle(Dot* d) : Figure(3) {
    this->dots[0] = d[0];
    this->dots[1] = d[1];
    this->dots[2] = d[2];
}

Triangle::~Triangle() {};

Triangle::operator double() {
    double S;
    S = 0.5 * std::fabs((dots[1].x - dots[0].x) * (dots[2].y - dots[0].y) \
    - (dots[2].x - dots[0].x) * (dots[1].y - dots[0].y));
    return S;
};