#pragma once
#include "storage.h"
#include "courier.h"
#include "order.h"
#include <vector>
#include <string>

struct DatabaseManager {
	string storage_file_name = "./storage.txt";
	string order_file_name = "./order.txt";
	string courier_file_name = "./courier.txt";

	void save(vector<abstracts::Storage> &storages);
	void read(vector<abstracts::Storage>& storages);
	string add_storage(vector<abstracts::Storage>& storages, Socket&);
	string remove_storage(
		vector<abstracts::Storage>& storages, 
		vector<abstracts::Courier>& couriers,
		vector<abstracts::Order>& orders,
		int storage_id);

	void save(vector<abstracts::Courier>& couriers);
	void read(vector<abstracts::Courier>& couriers);
	string add_courier(
		vector<abstracts::Courier>& couriers,
		vector<abstracts::Storage>& storages, 
		Socket&);
	string remove_courier(
		vector<abstracts::Courier>& couriers,
		int courier_id);

	void save(vector<abstracts::Order>& orders);
	void read(vector<abstracts::Order>& orders);
	string add_order(
		vector<abstracts::Order>& orders,
		vector<abstracts::Storage>& storages,
		Socket&);
};