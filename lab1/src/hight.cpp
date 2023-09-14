#include<iostream>

int hight(int UpSpeed, int DownSpeed, int desiredHeight) {

    
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