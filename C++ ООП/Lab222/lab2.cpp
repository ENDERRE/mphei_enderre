#include <iostream>
#include <limits>
#include <cmath> 
#include <string>
#include "lab2_s.cpp"
#include "global.hpp"


int main() {
    using namespace Geometry;

    // Массивы указателей
    Point* points[10] = {nullptr};
    Complex* complexes[10] = {nullptr};
    size_t pointCount = 0;
    size_t complexCount = 0;

    int choice;
    do {
        menu();
        choice = inputInt("Введите номер пункта: ");

        switch(choice) {
            case 1: { // Создать точку
                if (pointCount >= 10) {
                    std::cout << "Лимит точек достигнут.\n";
                    break;
                }
                points[pointCount] = new Point();
                points[pointCount]->input("Point " + std::to_string(pointCount+1));
                std::cout << "Создана точка: ";
                points[pointCount]->print();
                pointCount++;
                break;
            }
            case 2: { // Создать комплексное число
                if (complexCount >= 10) {
                    std::cout << "Лимит комплексных чисел достигнут.\n";
                    break;
                }
                complexes[complexCount] = new Complex();
                complexes[complexCount]->input("Complex " + std::to_string(complexCount+1));
                std::cout << "Создано число: ";
                complexes[complexCount]->print();
                complexCount++;
                break;
            }
            case 3: { // Вывести все точки
                if (pointCount == 0) {
                    std::cout << "Нет созданных точек.\n";
                } else {
                    for (size_t i=0; i<pointCount; ++i) {
                        std::cout << i+1 << ". ";
                        points[i]->print();
                    }
                }
                break;
            }
            case 4: { // Вывести все числа
                if (complexCount == 0) {
                    std::cout << "Нет созданных комплексных чисел.\n";
                } else {
                    for (size_t i=0; i<complexCount; ++i) {
                        std::cout << i+1 << ". ";
                        complexes[i]->print();
                    }
                }
                break;
            }
            case 5: { // Сложение точек
                if (pointCount < 2) {
                    std::cout << "Недостаточно точек.\n";
                    break;
                }
                int idx1 = inputInt("Введите номер первой точки (1-"+std::to_string(pointCount)+"): ");
                int idx2 = inputInt("Введите номер второй точки (1-"+std::to_string(pointCount)+"): ");
                if (idx1<1 || idx1>=(int)pointCount+1 || idx2<1 || idx2>=(int)pointCount+1) {
                    std::cout << "Некорректный индекс.\n";
                    break;
                }
                Point res = points[idx1-1]->add(*points[idx2-1]);
                std::cout << "Результат: ";
                res.print();
                break;
            }
            case 6: { // Сложение комплексных
                if (complexCount < 2) {
                    std::cout << "Недостаточно чисел.\n";
                    break;
                }
                int idx1 = inputInt("Введите номер первого числа (1-"+std::to_string(complexCount)+"): ");
                int idx2 = inputInt("Введите номер второго числа (1-"+std::to_string(complexCount)+"): ");
                if (idx1<1 || idx1>=(int)complexCount+1 || idx2<1 || idx2>=(int)complexCount+1) {
                    std::cout << "Некорректный индекс.\n";
                    break;
                }
                Complex res = complexes[idx1-1]->add(*complexes[idx2-1]);
                std::cout << "Результат: ";
                res.print();
                break;
            }
            case 7: { // Перестановка точек
                if (pointCount < 2) {
                    std::cout << "Недостаточно точек.\n";
                    break;
                }
                int idx1 = inputInt("Введите номер первой точки (1-"+std::to_string(pointCount)+"): ");
                int idx2 = inputInt("Введите номер второй точки (1-"+std::to_string(pointCount)+"): ");
                if (idx1<1 || idx1>=(int)pointCount+1 || idx2<1 || idx2>=(int)pointCount+1) {
                    std::cout << "Некорректный индекс.\n";
                    break;
                }
                points[idx1-1]->swap(*points[idx2-1]);
                std::cout << "Точки обменяны.\n";
                break;
            }
            case 8: { // Перестановка чисел
                if (complexCount < 2) {
                    std::cout << "Недостаточно чисел.\n";
                    break;
                }
                int idx1 = inputInt("Введите номер первого числа (1-"+std::to_string(complexCount)+"): ");
                int idx2 = inputInt("Введите номер второго числа (1-"+std::to_string(complexCount)+"): ");
                if (idx1<1 || idx1>=(int)complexCount+1 || idx2<1 || idx2>=(int)complexCount+1) {
                    std::cout << "Некорректный индекс.\n";
                    break;
                }
                complexes[idx1-1]->swap(*complexes[idx2-1]);
                std::cout << "Числа обменяны.\n";
                break;
            }
            case 9:
                std::cout << "Выход.\n";
                break;
            default:
                std::cout << "Некорректный пункт.\n";
        }

    } while (choice != 9);

    // Очистка динамически выделенной памяти
    for (size_t i=0; i<pointCount; ++i) {
        delete points[i];
    }
    for (size_t i=0; i<complexCount; ++i) {
        delete complexes[i];
    }

    return 0;
}