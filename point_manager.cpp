#include "point_manager.h"
#include <cmath>

namespace singletones {
    // Функция для вычисления расстояния между двумя точками
    double PointManager::get_distance(abstracts::Point& a, abstracts::Point& b) {
        // Используем теорему Пифагора для вычисления расстояния
        return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }

    // Функция для проверки равенства двух точек
    bool PointManager::equal(abstracts::Point& a, abstracts::Point& b) {
        // Сравниваем координаты x и y двух точек
        return a.x == b.x && a.y == b.y; // Используем && вместо 'and' для большей читаемости
    }

    // Функция для создания новой точки на основе двух существующих
    // и заданной скорости в км/ч
    abstracts::Point PointManager::new_point(abstracts::Point& a, abstracts::Point& b, double speed_kmh) {
        // Вычисляем расстояние между точками a и b
        double distance = get_distance(a, b);
        // Вычисляем время в часах, необходимое для преодоления этого расстояния с заданной скоростью
        double hours = distance / speed_kmh;

        // Если время меньше или равно 1 часу, возвращаем точку b
        if (hours <= 1)
            return b;

        // Создаём новую точку, которая будет находиться между a и b
        abstracts::Point result;
        // Вычисляем координаты новой точки, пропорционально времени
        result.x = a.x + (b.x - a.x) / hours;
        result.y = a.y + (b.y - a.y) / hours;

        // Возвращаем новую точку
        return result;
    }
}
