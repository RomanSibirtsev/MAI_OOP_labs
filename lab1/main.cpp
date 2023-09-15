#include <iostream>

#include "hight.hpp"

int main() {

    int UpSpeed, DownSpeed, desiredHeight;

    std::cout << "Введите скорость роста [метров/день] ";
    std::cin >> UpSpeed;
    std::cout << "Введите скорость уменьшения [метров/ночь] ";
    std::cin >> DownSpeed;
    std::cout << "Введите конечную высоту [метров] ";
    std::cin >> desiredHeight;

    std::cout << hight(UpSpeed, DownSpeed, desiredHeight) << std::endl;
}