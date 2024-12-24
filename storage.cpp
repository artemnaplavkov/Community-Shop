#include "storage.h"
#include <sstream>

namespace abstracts {
	string Storage::print() {
		ostringstream os;
		os << "id=" << id << "; " << pos.print();
		return os.str();
	}
	void Storage::input(Socket& socket) {
		socket.set("id=");
		id = atoi(socket.get().data());
		pos.input(socket);
	}
	void Storage::save(ofstream& os) {
		os << id << " ";
		pos.save(os);
	}
	void Storage::read(ifstream& is) {
		is >> id;
		pos.read(is);
	}
}
