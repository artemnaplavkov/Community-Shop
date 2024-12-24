#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include "courier.h"

using namespace std;

namespace abstracts {
	string Courier::print() {
        ostringstream os;
        os
			<< "id=" << id
			<< "; speed_kmh=" << speed_kmh
			<< "; storage_id=" << storage_id
			<< "; current_order_id=" << current_order_id << "; "
            << pos.print();
        return os.str();
	}
    void Courier::input(Socket& socket) {
        socket.set("id=");
        id = atoi(socket.get().data());
        socket.set("speed_kmh=");
        speed_kmh = atoi(socket.get().data());
        socket.set("storage_id=");
        storage_id = atoi(socket.get().data());
        current_order_id = 0;
        pos.input(socket);
	}
    void Courier::save(ofstream& os) {
		os << id << " "
			<< speed_kmh << " "
			<< storage_id << " "
			<< current_order_id << " ";
		pos.save(os);
	}
    void Courier::read(ifstream& is) {
		is >> id >> speed_kmh >> storage_id >> current_order_id;
		pos.read(is);
	}
}
