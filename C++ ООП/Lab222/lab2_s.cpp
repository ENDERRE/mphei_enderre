#include <iostream>
#include <limits>
#include <cmath> 
#include <string>
#include "lab2_s.hpp"
#include "global.hpp"
namespace Geometry {
    int inputInt(const std::string& prompt) {
        int value;
        while (true) {
            std::cout << prompt;
            if (std::cin >> value) {
                return value;
            } else {
                std::cout << "Некорректный ввод. Попробуйте снова.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
}
