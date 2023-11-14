#include "Square.hpp"
#include "Triangle.hpp"
#include "Rectangle.hpp"
#include "Array.hpp"
#include <iostream>
#include <vector>

int main() {
    Triangle s, d, k;
    //std::vector<Figure*> arr(5);
    Figure *arr[3];
    std::cin >> s;
    std::cin >> d;
    arr[0] = &s;
    arr[1] = &d;
    arr[2] = arr[1];
    // arr.erase(arr.begin() + 1);
    for (int i = 0; i < 3; ++i) {
        std::cout << *arr[i];
    }

    Square sq = {Dot{0, 0}, Dot{0, 2}, Dot{2, 2}, Dot{2, 0}}; 
    Rectangle r = {Dot{0, 0}, Dot{0, 2}, Dot{4, 2}, Dot{4, 0}};
    Triangle t = {Dot{0, 0}, Dot{0, 2}, Dot{2, 2}}; 
    Array arr1 = {&sq, &r, &t};
    arr1.Centers();
    arr1.Areas();
}