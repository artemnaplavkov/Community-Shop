#pragma once
#include <fstream>

namespace abstracts {

	struct Point {
		double x; // Объявляем х,у для задания координат точки
		double y;
		void input(); // Метод для ввода координат точки
		void print();  // Метод для вывода координат точки на экран
		void save(std::ofstream& os);  // Метод для сохранения координат точки в файл
		void read(std::ifstream& is); // Метод для чтения координат точки из файла
	};
}
