#pragma once

#include "Figure.hpp"

class Rectangle : public Figure {
public:
    Rectangle();
    Rectangle(const std::initializer_list<Dot> & t) : Figure(t) {};
    ~Rectangle();
    operator double() override;
};