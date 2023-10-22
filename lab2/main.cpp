#include <iostream>

#include "Octal.hpp"

int main() {
    Octal a = {"199"};
    Octal b = {'1', '1', '1'};
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
}