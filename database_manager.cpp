#include "database_manager.h"
#include <sstream>

void DatabaseManager::save(vector<abstracts::Storage>& storages) {
	ofstream os(storage_file_name);
	for (int i = 0; i < storages.size(); i++) {
		storages[i].save(os);
		os << "\n";
	}
}
void DatabaseManager::read(vector<abstracts::Storage>& storages) {
	storages.clear();
	ifstream is(storage_file_name);
	while (not is.eof()) {
		abstracts::Storage storage;
		storage.read(is);
		if (is.good())
			storages.push_back(storage);
	}
}
string DatabaseManager::add_storage(vector<abstracts::Storage>& storages, Socket& socket) {
	abstracts::Storage storage; 
	storage.input(socket);
	for (vector<abstracts::Storage>::iterator ptr = storages.begin(); ptr != storages.end(); ptr++) {
		if (ptr->id == storage.id) {
			return "storage id is already used\n";
		}
	}
	storages.push_back(storage);
	return "";
}
string DatabaseManager::remove_storage(
	vector<abstracts::Storage>& storages,
	vector<abstracts::Courier>& couriers,
	vector<abstracts::Order>& orders,
	int storage_id) {
	for (vector<abstracts::Courier>::iterator ptr = couriers.begin(); ptr != couriers.end(); ptr++) {
		if (ptr->storage_id == storage_id) {
			return "there is courier on storage\n";
		}
	}
	for (vector<abstracts::Order>::iterator ptr = orders.begin(); ptr != orders.end(); ptr++) {
		if (ptr->storage_id == storage_id and ptr->state!= abstracts::completed) {
			return  "there is incomlete order on storage\n";
		}
	}
	for (vector<abstracts::Storage>::iterator ptr = storages.begin(); ptr != storages.end(); ptr++) {
		if (ptr->id != storage_id)
			continue;
		storages.erase(ptr);
		break;
	}
	return "";
}

void DatabaseManager::save(vector<abstracts::Courier>& couriers) {
	ofstream os(courier_file_name);
	for (int i = 0; i < couriers.size(); i++) {
		couriers[i].save(os);
		os << "\n";
	}
}
void DatabaseManager::read(vector<abstracts::Courier>& couriers) {
	couriers.clear();
	ifstream is(courier_file_name);
	while (not is.eof()) {
		abstracts::Courier courier;
		courier.read(is);
		if (is.good())
			couriers.push_back(courier);
	}
}
string DatabaseManager::add_courier(
	vector<abstracts::Courier>& couriers,
	vector<abstracts::Storage>& storages, 
	Socket& socket){
	abstracts::Courier courier;
	courier.input(socket);
	for (vector<abstracts::Courier>::iterator ptr = couriers.begin(); ptr != couriers.end(); ptr++) {
		if (ptr->id == courier.id) {
			return "courier id is already used";
		}
	}
	for (vector<abstracts::Storage>::iterator ptr = storages.begin(); ptr != storages.end(); ptr++) {
		if (ptr->id == courier.storage_id) {
			couriers.push_back(courier);
			return "";
		}
	}
	return "invalid storage";
}
string DatabaseManager::remove_courier(
	vector<abstracts::Courier>& couriers,
	int courier_id){
	ostringstream os;
	for (vector<abstracts::Courier>::iterator ptr = couriers.begin(); ptr != couriers.end(); ptr++) {
		if (ptr->id != courier_id)
			continue;
		if (ptr->current_order_id != 0) {
			os << "courier is delivering the order";
			break;
		}
		couriers.erase(ptr);
		break;
	}
	return os.str();
}

void DatabaseManager::save(vector<abstracts::Order>& orders) {
	ofstream os(order_file_name);
	for (int i = 0; i < orders.size(); i++) {
		orders[i].save(os);
		os << "\n";
	}
}
void DatabaseManager::read(vector<abstracts::Order>& orders) {
	orders.clear();
	ifstream is(order_file_name);
	while (not is.eof()) {
		abstracts::Order order;
		order.read(is);
		if (is.good())
			orders.push_back(order);
	}
}
string DatabaseManager::add_order(
		vector<abstracts::Order>& orders,
		vector<abstracts::Storage>& storages, 
		Socket& socket) {
	abstracts::Order order;
	order.input(socket);
	for (vector<abstracts::Order>::iterator ptr = orders.begin(); ptr != orders.end(); ptr++) {
		if (ptr->id == order.id) {
			return  "order id is already used\n";
		}
	}
	for (vector<abstracts::Storage>::iterator ptr = storages.begin(); ptr != storages.end(); ptr++) {
		if (ptr->id == order.storage_id) {
			orders.push_back(order);
			return "";
		}
	}
	return "there is no storage with this id\n";
}