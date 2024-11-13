#include "storage.h"
#include <iostream>

namespace abstracts {
	void Storage::print() {
		std::cout << "id=" << id << "; ";
		pos.print();
	}
	void Storage::input() {
		std::cout << "id=";
		std::cin >> id;
		pos.input();
	}
	void Storage::save(std::ofstream& os) {
		os << id << " ";
		pos.save(os);
	}
	void Storage::read(std::ifstream& is) {
		is >> id;
		pos.read(is);
	}
}
