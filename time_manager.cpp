#include "time_manager.h"
#include "point_manager.h"

int find_storage(std::vector<abstracts::Storage>& storages, int storage_id) {   // Ищет хранилище с совпадающим id
	for (int i = 0; i < storages.size();i++) {
		if (storages[i].id == storage_id)
			return i;
	}
	return -1;
}

int find_courier(std::vector<abstracts::Courier>& couriers, abstracts::Storage& storage) {   // Ищет курьера связанного с хранилищем
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

int find_courier(std::vector<abstracts::Courier>& couriers, abstracts::Order& order) {  // Ищет курьера, который уже выполняет заказ
	for (int i = 0; i < couriers.size(); i++) {
		if (couriers[i].current_order_id != order.id)
			continue;
		if (!singletones::PointManager::equal(couriers[i].pos, order.target))
			continue;
		return i;
	}
	return -1;
}
