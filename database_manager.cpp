#include "database_manager.h"
#include <iostream>

void DatabaseManager::save(std::vector<abstracts::Storage>& storages) {
	std::ofstream os(storage_file_name);
	for (int i = 0; i < storages.size(); i++) {
		storages[i].save(os);
		os << "\n";
	}
}
void DatabaseManager::read(std::vector<abstracts::Storage>& storages) {
	storages.clear();
	std::ifstream is(storage_file_name);
	while (not is.eof()) {
		abstracts::Storage storage;
		storage.read(is);
		if (is.good())
			storages.push_back(storage);
	}
}
void DatabaseManager::add_storage(std::vector<abstracts::Storage>& storages) {
	abstracts::Storage storage;
	storage.input();
	for (std::vector<abstracts::Storage>::iterator ptr = storages.begin(); ptr != storages.end(); ptr++) {
		if (ptr->id == storage.id) {
			std::cout << "storage id is already used\n";
			return;
		}
	}
	storages.push_back(storage);
}
void DatabaseManager::remove_storage(
	std::vector<abstracts::Storage>& storages,
	std::vector<abstracts::Courier>& couriers,
	std::vector<abstracts::Order>& orders,
	int storage_id) {
	for (std::vector<abstracts::Courier>::iterator ptr = couriers.begin(); ptr != couriers.end(); ptr++) {
		if (ptr->storage_id == storage_id) {
			std::cout << "there is courier on storage\n";
			return;
		}
	}
	for (std::vector<abstracts::Order>::iterator ptr = orders.begin(); ptr != orders.end(); ptr++) {
		if (ptr->storage_id == storage_id and ptr->state!= abstracts::completed) {
			std::cout << "there is incomlete order on storage\n";
			return;
		}
	}
	for (std::vector<abstracts::Storage>::iterator ptr = storages.begin(); ptr != storages.end(); ptr++) {
		if (ptr->id != storage_id)
			continue;
		storages.erase(ptr);
		break;
	}
}

void DatabaseManager::save(std::vector<abstracts::Courier>& couriers) {
	std::ofstream os(courier_file_name);
	for (int i = 0; i < couriers.size(); i++) {
		couriers[i].save(os);
		os << "\n";
	}
}
void DatabaseManager::read(std::vector<abstracts::Courier>& couriers) {
	couriers.clear();
	std::ifstream is(courier_file_name);
	while (not is.eof()) {
		abstracts::Courier courier;
		courier.read(is);
		if (is.good())
			couriers.push_back(courier);
	}
}
void DatabaseManager::add_courier(
	std::vector<abstracts::Courier>& couriers,
	std::vector<abstracts::Storage>& storages){
	abstracts::Courier courier;
	courier.input();
	for (std::vector<abstracts::Courier>::iterator ptr = couriers.begin(); ptr != couriers.end(); ptr++) {
		if (ptr->id == courier.id) {
			std::cout << "courier id is already used\n";
			return;
		}
	}
	for (std::vector<abstracts::Storage>::iterator ptr = storages.begin(); ptr != storages.end(); ptr++) {
		if (ptr->id == courier.storage_id) {
			couriers.push_back(courier);
			return;
		}
	}
	std::cout << "invalid storage\n";
}
void DatabaseManager::remove_courier(
	std::vector<abstracts::Courier>& couriers,
	int courier_id){
	for (std::vector<abstracts::Courier>::iterator ptr = couriers.begin(); ptr != couriers.end(); ptr++) {
		if (ptr->id != courier_id)
			continue;
		if (ptr->current_order_id != 0) {
			std::cout << "courier is delivering the order";
			break;
		}
		couriers.erase(ptr);
		break;
	}
}

void DatabaseManager::save(std::vector<abstracts::Order>& orders) {
	std::ofstream os(order_file_name);
	for (int i = 0; i < orders.size(); i++) {
		orders[i].save(os);
		os << "\n";
	}
}
void DatabaseManager::read(std::vector<abstracts::Order>& orders) {
	orders.clear();
	std::ifstream is(order_file_name);
	while (not is.eof()) {
		abstracts::Order order;
		order.read(is);
		if (is.good())
			orders.push_back(order);
	}
}
void DatabaseManager::add_order(
		std::vector<abstracts::Order>& orders,
		std::vector<abstracts::Storage>& storages) {
	abstracts::Order order;
	order.input();
	for (std::vector<abstracts::Order>::iterator ptr = orders.begin(); ptr != orders.end(); ptr++) {
		if (ptr->id == order.id) {
			std::cout << "order id is already used\n";
			return;
		}
	}
	for (std::vector<abstracts::Storage>::iterator ptr = storages.begin(); ptr != storages.end(); ptr++) {
		if (ptr->id == order.storage_id) {
			orders.push_back(order);
			return;
		}
	}
	std::cout << "there is no storage with this id\n";
}