#pragma once
#include "courier.h"
#include "order.h"
#include "storage.h"
#include <vector>
struct TimeManager{       // Управление временем
	void time_shift(int hours,       //  кол-во часов для смещения времени
		std::vector<abstracts::Storage>& storages,
		std::vector<abstracts::Courier>& couriers,
		std::vector<abstracts::Order>& orders);
private:
	void assign_orders(     //  Получает вектор курьеров и заказов, используем для распределения или назначения заказов курьерам
		std::vector<abstracts::Storage>& storages,
		std::vector<abstracts::Courier>& couriers,
		std::vector<abstracts::Order>& orders);
	void one_hour_move(  //  Принимает вектора курьеров и заказов, симулирует изменения в системе за один часЫ
		std::vector<abstracts::Storage>& storages,
		std::vector<abstracts::Courier>& couriers,
		std::vector<abstracts::Order>& orders);
	void complete_orders(   // обрабатывет завершение или выполнение заказов
		std::vector<abstracts::Storage>& storages,
		std::vector<abstracts::Courier>& couriers,
		std::vector<abstracts::Order>& orders);
};
