#include <iostream>
#include <string>

std::string hight(int UpSpeed, int DownSpeed, int desiredHeight) {

    
    int currentHeight = 0;
    int dayCount = 1;
    bool day = 0;

    if ((UpSpeed <= DownSpeed) && (desiredHeight != 0)) {
        return "растение никогда не достигнет заданного уровня!!!";
    }
    
    if ((desiredHeight % (UpSpeed - DownSpeed) != 0) and ((desiredHeight - UpSpeed) % (UpSpeed - DownSpeed) != 0)) {
        return "растение никогда не достигнет заданного уровня!!!";
    }

    while (currentHeight < desiredHeight) {

        currentHeight += UpSpeed;
        day = true;
        std::cout << "После дня " << dayCount << " --> " << currentHeight << std::endl;

        if (currentHeight == desiredHeight) break;

        currentHeight -= DownSpeed;
        day = false;
        std::cout << "После ночи " << dayCount << " --> " << currentHeight << std::endl;

        ++dayCount;

    }

    std::string result;
    if (day) {
        result = "растение достигнет заданного уровня в " + std::to_string(dayCount) +" день";
    } else {
        result = "растение достигнет заданного уровня в " + std::to_string(dayCount - 1) + " ночь";
    }

    return result;

}