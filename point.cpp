#include "point.h"
#include <iostream>

namespace abstracts {
    // Метод для ввода координат точки
    void Point::input() {
        std::cout << "x=";
        std::cin >> x;
        std::cout << "y=";
        std::cin >> y;
    }

    // Метод для вывода координат точки на экран
    void Point::print() {
        std::cout << "x=" << x << "; " << "y=" << y << "; "; //
    }

    // Метод для сохранения координат точки в файл
    void Point::save(std::ofstream& os) {
        os << x << " " << y << " "; // Записываем координаты x и y в файл, разделенные пробелом
    }

    // Метод для чтения координат точки из файла
    void Point::read(std::ifstream& is) {
        is >> x >> y; // Считываем координаты x и y из файла
    }
}
