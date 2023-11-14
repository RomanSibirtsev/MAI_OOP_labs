#pragma once
#include "Figure.hpp"

class Square : public Figure {
private:

public:
    Square();
    Square(const std::initializer_list<Dot> & t) : Figure(t) {};
    operator double() override;
    ~Square();
};