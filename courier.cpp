#include "courier.h"
#include <iostream>

namespace abstracts {
	void Courier::print() {
		std::cout
			<< "id=" << id
			<< "; speed_kmh=" << speed_kmh
			<< "; storage_id=" << storage_id
			<< "; current_order_id=" << current_order_id << "; ";
		pos.print();
	}
	void Courier::input() {
		std::cout << "id=";
		std::cin >> id;
		std::cout << "speed_kmh=";
		std::cin >> speed_kmh;
		std::cout << "storage_id=";
		std::cin >> storage_id;
		current_order_id = 0;
		pos.input();
	}
	void Courier::save(std::ofstream& os) {
		os << id << " "
			<< speed_kmh << " "
			<< storage_id << " "
			<< current_order_id << " ";
		pos.save(os);
	}
	void Courier::read(std::ifstream& is) {
		is >> id >> speed_kmh >> storage_id >> current_order_id;
		pos.read(is);
	}
}