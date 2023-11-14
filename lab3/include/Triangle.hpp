#pragma once
#include "Figure.hpp"

class Triangle : public Figure {
private:

public:
    Triangle();
    Triangle(Dot* d);
    Triangle(const std::initializer_list<Dot> & t) : Figure(t) {};
    ~Triangle();
    operator double() override;
};