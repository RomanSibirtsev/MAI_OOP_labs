#include <iostream>

#include "Octal.hpp"

int main() {
    size_t x = 10;
    u_char t = 5;
    Octal a = {"67777777"};
    Octal b = {"60000000"};
    std::cout << a << std::endl << b << std::endl;
    //std::cout << (a-b) << std::endl;
    Octal c;
    c = a + b;
    std::cout << c << std::endl;
    //std::cout << (b == a) << std::endl;
}