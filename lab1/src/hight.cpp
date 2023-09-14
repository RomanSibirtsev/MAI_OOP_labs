#include<iostream>

int hight() {

    int UpSpeed, DownSpeed, desiredHeight;
    std::cout << "Введите скорость роста [метров/день] ";
    std::cin >> UpSpeed;
    std::cout << "Введите скорость уменьшения [метров/ночь] ";
    std::cin >> DownSpeed;
    std::cout << "Введите конечную высоту [метров] ";
    std::cin >> desiredHeight;

    int currentHeight = 0;
    int dayCount = 1;

    if ((UpSpeed <= DownSpeed) && (desiredHeight != 0)) {
        return -1;
    }

    while (currentHeight != desiredHeight) {

        currentHeight += UpSpeed;
        std::cout << "После дня " << dayCount << " --> " << currentHeight << std::endl;

        if (currentHeight == desiredHeight) break;

        currentHeight -= DownSpeed;
        std::cout << "После ночи " << dayCount << " --> " << currentHeight << std::endl;

        ++dayCount;

    }

    return 0;

}