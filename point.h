#pragma once
#include <fstream>
#include <string>
#include "socket.h"

using namespace std;

namespace abstracts {

	struct Point {
		double x;
		double y;
        void input(Socket& socket);
        string print();
		void save(ofstream& os);
		void read(ifstream& is);
	};
}

