#include <iostream>

#include "Octal.hpp"

int main() {
    size_t x = 10;
    u_char t = 5;
    Octal a("1111");
    Octal b("1111");
    std::cout << (b == a);
}