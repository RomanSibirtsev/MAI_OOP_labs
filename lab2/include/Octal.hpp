// Создать класс Octal для работы с беззнаковыми целыми восьмеричными числами, используя для представле-
// ния числа массив из элементов типа unsigned char, каждый элемент которого является восьмеричной циф-
// рой. Младшая цифра имеет меньший индекс (единицы — в нулевом элементе массива).
#pragma once

#include <string>
#include <vector>
#include <initializer_list>
#include <iostream>
#include <algorithm>

class Octal
{
public:
    Octal();
    Octal(const size_t & n, unsigned char t);
    Octal(const std::initializer_list<unsigned char> &t);
    Octal(const std::string &t);
    Octal(const Octal& other);
    Octal(Octal&& other) noexcept;
    Octal operator+(Octal const& obj);
    Octal operator-(Octal const& obj);
    void operator=(Octal const& obj);
    bool operator>(Octal const& obj);
    bool operator<(Octal const& obj);
    bool operator==(Octal const& obj) const;
    ~Octal() noexcept;
    u_char* data;
    size_t size;
};

std::ostream& operator<<(std::ostream& os, const Octal& obj);