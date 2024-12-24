#pragma once
#include <fstream>
#include <string>
#include "point.h"
#include "socket.h"

using namespace std;

namespace abstracts {
	struct Courier {
		int id;
		double speed_kmh;
		int storage_id;
		int current_order_id;
		Point pos;

		string print();
        void input(Socket&);
		void save(ofstream& os);
		void read(ifstream& is);
	};
}
