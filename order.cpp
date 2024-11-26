#include "order.h"
#include "point.h"
#include <iostream>

namespace abstracts {
	void Order::print() {
		std::cout
			<< "id=" << id
			<< "; storage_id=" << storage_id
			<< "; state=" << state << "; ";
		target.print();
	}
	//mainframe 
	void Order::input() {
		std::cout << "id=";
		std::cin >> id;
		std::cout << "storage_id=";
		std::cin >> storage_id;
	    state = not_processed;
		target.input();

	}
	//replace?
	void Order::save(std::ofstream& os) {
		os << id << " "
			<< storage_id << " "
			<< state << " ";
		target.save(os);
	}
	//read from mainframe
	void Order::read(std::ifstream& is) {
		is >> id >> storage_id >> state;
		target.read(is);
	}
}