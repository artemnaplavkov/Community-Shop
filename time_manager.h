#pragma once
#include "courier.h"
#include "order.h"
#include "storage.h"
#include <vector>
struct TimeManager{
	void time_shift(int hours,
		vector<abstracts::Storage>& storages,
		vector<abstracts::Courier>& couriers,
		vector<abstracts::Order>& orders);
private:
	void assign_orders(
		vector<abstracts::Storage>& storages,
		vector<abstracts::Courier>& couriers,
		vector<abstracts::Order>& orders);
	void one_hour_move(
		vector<abstracts::Storage>& storages,
		vector<abstracts::Courier>& couriers,
		vector<abstracts::Order>& orders);
	void complete_orders(
		vector<abstracts::Storage>& storages,
		vector<abstracts::Courier>& couriers,
		vector<abstracts::Order>& orders);
};
