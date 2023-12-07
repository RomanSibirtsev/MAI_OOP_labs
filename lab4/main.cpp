#include "Square.hpp"
#include "Triangle.hpp"
#include "Rectangle.hpp"
#include "Array.hpp"
#include <iostream>
#include <vector>
#include <memory>

template <class T>
struct arr {
    Array<std::shared_ptr<Figure<T>>> data;
};

int main() {
    int command;
    Array<std::shared_ptr<Figure<double>>> fig_arr;
    std::cout << "Comands:"  << std::endl;
    std::cout << "1 - create new figure;" << std::endl;
    std::cout << "2 - delete the figure;" << std::endl;
    std::cout << "3 - calculate the area of the figures;" << std::endl;
    std::cout << "4 - calculate the total area of the figures;" << std::endl;
    std::cout << "0 - exit." << std::endl;
    while(1) {
        std::cin >> command;
        if (command == 0) {
            break;
        } else if (command == 1) {
            int fig_type;
            std::cout << "1 - Rectangle" << std::endl;
            std::cout << "2 - Square" << std::endl;
            std::cout << "3 - Triangle" << std::endl;
            std::cin >> fig_type;
            if (fig_type < 1 || fig_type > 3) {
                std::cout << "wrong figure type" << std::endl;
            } else if (fig_type == 1) {
                Rectangle<double> rec;
                std::cin >> rec;
                fig_arr.push_back(std::make_shared<Rectangle<double>>(rec));
                std::cout << "Rectangle is added" << std::endl;
            } else if (fig_type == 2) {
                Square<double> sq;
                std::cin >> sq;
                fig_arr.push_back(std::make_shared<Square<double>>(sq));
                std::cout << "Square is added" << std::endl;
            } else if (fig_type == 3) {
                Triangle<double> tr;
                std::cin >> tr;
                fig_arr.push_back(std::make_shared<Triangle<double>>(tr));
                std::cout << "Triangle is added" << std::endl;
            }
        } else if (command == 2) {
            int id;
            std::cout << "enter id " << std::endl;
            std::cin >> id;
            fig_arr.remove(id);
        } else if (command == 3) {
            std::cout << "area of all figures: " << std::endl;
            fig_arr.get_area();
            std::cout << std::endl;
        } else if (command == 4) {
            std::cout << "total area = ";
            std::cout << fig_arr.get_total_area() << std::endl;
        }
    }
}