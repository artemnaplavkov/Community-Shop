#pragma once
#include "point.h"
#include <fstream>

namespace abstracts {

	struct Storage {
		int id;
		Point pos;
		
		void print();
		void input();
		void save(std::ofstream &os);
		void read(std::ifstream& is);
	};

}