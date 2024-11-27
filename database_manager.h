#pragma once
#include "storage.h"
#include "courier.h"
#include "order.h"
#include <vector>
#include <string>

struct DatabaseManager {
	std::string storage_file_name = "./storage.txt";
	std::string order_file_name = "./order.txt";
	std::string courier_file_name = "./courier.txt";

	void save(std::vector<abstracts::Storage> &storages);
	void read(std::vector<abstracts::Storage>& storages);
	void add_storage(std::vector<abstracts::Storage>& storages);
	void remove_storage(
		std::vector<abstracts::Storage>& storages, 
		std::vector<abstracts::Courier>& couriers,
		std::vector<abstracts::Order>& orders,
		int storage_id);

	void save(std::vector<abstracts::Courier>& couriers);
	void read(std::vector<abstracts::Courier>& couriers);
	void add_courier(
		std::vector<abstracts::Courier>& couriers,
		std::vector<abstracts::Storage>& storages);
	void remove_courier(
		std::vector<abstracts::Courier>& couriers,
		int courier_id);

	void save(std::vector<abstracts::Order>& orders);
	void read(std::vector<abstracts::Order>& orders);
	void add_order(
		std::vector<abstracts::Order>& orders,
		std::vector<abstracts::Storage>& storages);
};