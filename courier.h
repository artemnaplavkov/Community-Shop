#pragma once
#include "point.h"
#include <fstream>

namespace abstracts {
	struct Courier {
		int id;
		double speed_kmh;
		int storage_id;
		int current_order_id;
		Point pos;

		void print();
		void input();
		void save(std::ofstream& os);
		void read(std::ifstream& is);
	};
}
