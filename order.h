#pragma once
#include "point.h"

namespace abstracts {
	int const not_processed = 0;
	int const in_progress = 1;
	int const completed = 2;

	struct Order {
		int id;
		int storage_id;
		int state;
		Point target;

		void print();
		void input();
		void save(std::ofstream& os);
		void read(std::ifstream& is);
	};
}