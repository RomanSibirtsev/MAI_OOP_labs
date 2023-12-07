#pragma once

#include "Figure.hpp"
#include "Triangle.hpp"
#include <memory>

template <class T>
class Rectangle : public Figure<T> {
public:
    Rectangle(const std::initializer_list<Dot<T>> & t) : Figure<T>(t) {};
    Rectangle() : Figure<T>(4) {};
    ~Rectangle() {};
    operator double () const override {
        Dot<T> d[] = {this->dots[0], this->dots[1], this->dots[2]};
        Triangle<T> t1(d);
        Dot<T> d2[] = {this->dots[1], this->dots[2], this->dots[3]};
        Triangle<T> t2(d2);

        double s;
        s = (double)t1 + (double)t2;

        return s;
    };
};