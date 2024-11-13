#pragma once
#include "point.h"
namespace singletones {
	struct PointManager{
		static double get_distance(abstracts::Point& a, abstracts::Point& b); // Функция для вычисления расстояния между двумя точками
		static bool equal(abstracts::Point& a, abstracts::Point& b); // Функция для проверки равенства двух точек
		static abstracts::Point new_point(abstracts::Point& a, abstracts::Point& b, double speed_kmh); // Функция для создания новой точки на основе двух существующих
    // и заданной скорости в км/ч
	};
}
