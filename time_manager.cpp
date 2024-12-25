#include "time_manager.h"
#include "point_manager.h"

int find_storage(vector<abstracts::Storage>& storages, int storage_id) {
	for (int i = 0; i < storages.size();i++) {
		if (storages[i].id == storage_id)
			return i;
	}
	return -1;
}

int find_courier(vector<abstracts::Courier>& couriers, abstracts::Storage& storage) {
	for (int i = 0; i < couriers.size(); i++) {
		if (couriers[i].storage_id != storage.id)
			continue;
		if (couriers[i].current_order_id != 0)
			continue;
		if (!singletones::PointManager::equal(couriers[i].pos, storage.pos))
			continue;
		return i;
	}
	return -1;
}

int find_courier(vector<abstracts::Courier>& couriers, abstracts::Order& order) {
	for (int i = 0; i < couriers.size(); i++) {
		if (couriers[i].current_order_id != order.id)
			continue;
		if (!singletones::PointManager::equal(couriers[i].pos, order.target))
			continue;
		return i;
	}
	return -1;
}

int find_order(vector<abstracts::Order>& orders, int order_id) {
	for (int i = 0; i < orders.size(); i++) {
		if (orders[i].id == order_id)
			return i;
	}
	return -1;
}

void TimeManager::time_shift(int hours,
	vector<abstracts::Storage>& storages,
	vector<abstracts::Courier>& couriers,
	vector<abstracts::Order>& orders) {
	for (int i = 0; hours > i; i++) {
		assign_orders(storages, couriers, orders);
		one_hour_move(storages, couriers, orders);
		complete_orders(storages, couriers, orders);
	}
}

void TimeManager::assign_orders(
	vector<abstracts::Storage>& storages,
	vector<abstracts::Courier>& couriers,
	vector<abstracts::Order>& orders) {
	for (int i = 0; i < orders.size();i++) {
		if (orders[i].state != abstracts::not_processed)
			continue;
		int storage_index = find_storage(storages, orders[i].storage_id);
		int courier_index = find_courier(couriers, storages[storage_index]);
		if (courier_index < 0)
			continue;
		orders[i].state = abstracts::in_progress;
		couriers[courier_index].current_order_id = orders[i].id;
	}
}
void TimeManager::one_hour_move(
	vector<abstracts::Storage>& storages,
	vector<abstracts::Courier>& couriers,
	vector<abstracts::Order>& orders) {
	for (int i = 0; i < couriers.size(); i++) {
		abstracts::Point a = couriers[i].pos;
		abstracts::Point b;
		if (couriers[i].current_order_id != 0) {
			int order_index = find_order(orders, couriers[i].current_order_id);
			b = orders[order_index].target;
		}
		else {
			int storage_index = find_storage(storages, couriers[i].storage_id);
			b = storages[storage_index].pos;
		}
		couriers[i].pos = singletones::PointManager::new_point(a, b, couriers[i].speed_kmh);
	}
}
void TimeManager::complete_orders(
	vector<abstracts::Storage>& storages,
	vector<abstracts::Courier>& couriers,
	vector<abstracts::Order>& orders) {
	for (int i = 0; i < orders.size(); i++) {
		if (orders[i].state != abstracts::in_progress)
			continue;
		int courier_index = find_courier(couriers, orders[i]);
		if (courier_index < 0)
			continue;
		orders[i].state = abstracts::completed;
		couriers[courier_index].current_order_id = 0;
	}
}
