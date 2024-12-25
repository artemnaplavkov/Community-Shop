#include "order.h"
#include "point.h"
#include <sstream>

namespace abstracts {
	string Order::print() {
		ostringstream os;
		os
			<< "id=" << id
			<< "; storage_id=" << storage_id
			<< "; state=" << state << "; "
			<< target.print();
		return os.str();
	}
	void Order::input(Socket& socket) {
		socket.set("id=");
		id = atoi(socket.get().data());
		socket.set("storage_id=");
		storage_id = atoi(socket.get().data());
	    state = not_processed;
		target.input(socket);

	}
	void Order::save(ofstream& os) {
		os << id << " "
			<< storage_id << " "
			<< state << " ";
		target.save(os);
	}
	void Order::read(ifstream& is) {
		is >> id >> storage_id >> state;
		target.read(is);
	}
}