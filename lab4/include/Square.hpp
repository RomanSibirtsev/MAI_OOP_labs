#pragma once
#include "Figure.hpp"
#include "Triangle.hpp"
#include <memory>

template <class T>
class Square : public Figure<T> {
public:
    Square(const std::initializer_list<Dot<T>> & t) : Figure<T>(t) {};
    Square() : Figure<T>{4} {};
    operator double () const override{
        Dot<T> d[] = {this->dots[0], this->dots[1], this->dots[2]};
        Triangle<T> t1(d);
        Dot<T> d2[] = {this->dots[1], this->dots[2], this->dots[3]};
        Triangle<T> t2(d2);

        double s;
        s = (double)t1 + (double)t2;

        return s;
    };

    ~Square() {};
};