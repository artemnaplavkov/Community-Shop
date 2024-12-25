#pragma once
#include "point.h"
#include <fstream>

namespace abstracts {

	struct Storage {
		int id;
		Point pos;
		
		string print();
		void input(Socket&);
		void save(ofstream &os);
		void read(ifstream& is);
	};

}
