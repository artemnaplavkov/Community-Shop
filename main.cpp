﻿#include "courier.h"
#include "order.h"
#include "storage.h"
#include "time_manager.h"
//#include "database_manager.h" - replace by the mainframe
#include <iostream>
#include <vector>


int main() {
	//realize by the mainframe
	std::vector<abstracts::Storage> storages;
	std::vector<abstracts::Courier> couriers;
	std::vector<abstracts::Order> orders;
	TimeManager time_manager;


	int stop = 0;
	while (stop != 1) {
		std::cout
			<< "\n1-save"
			<< "\n2-read"
			<< "\n3-time shift"
			<< "\n4-print storages"
			<< "\n5-add storage"
			<< "\n6-remove storage"
			<< "\n7-print couriers"
			<< "\n8-add courier"
			<< "\n9-remove courier"
			<< "\n10-print orders"
			<< "\n11-add order"
			<< "\n";
		int key;
		std::cin >> key;
		switch (key) {
			/*
		case 1:
			database.save(storages);
			database.save(couriers);
			database.save(orders);
			break;
		//(read from mainframe)	*/ 
		case 2:
			database.read(storages);
			database.read(couriers);
			database.read(orders);
			break;
		case 3: {
			std::cout << "hours=";
			int hours;
			std::cin >> hours;
			time_manager.time_shift(hours, storages, couriers, orders);
			break; //time skip
		}
		case 4:
			std::cout << "storages:\n";
			for (int i = 0; i < storages.size(); i++) {
				storages[i].print();
				std::cout << "\n";
			}
			break;
			/*
		case 5: {
			database.add_storage(storages);
			break;
		//would we realize work with database in mainframe?	*/
		}
		//removing storage, do we need it?
		case 6: {
			std::cout << "removing storage id=";
			int id;
			std::cin >> id;
			database.remove_storage(storages, couriers, orders, id);
			break;
		}
			  //print couriers
		case 7: {
			std::cout << "couriers from storage id=";
			int storage_id;
			std::cin >> storage_id;
			for (int i = 0; i < couriers.size(); i++) {
				if (couriers[i].storage_id == storage_id) {
					couriers[i].print();
					std::cout << "\n";
				}
			}
			break;
		}
			  /*
		case 8: {
			database.add_courier(couriers, storages);
			break;
		//adding a courier	*/
		}
	//remove courier
		case 9: {
			std::cout << "removing courier id=";
			int id;
			std::cin >> id;
			database.remove_courier(couriers, id);
			break;
		}
		case 10:
			std::cout << "orders:\n";
			for (int i = 0; i < orders.size(); i++) {
				if (orders[i].state != abstracts::completed) {
					orders[i].print();
					std::cout << "\n";
				}
			}
			break;
			//this is what we definitely need
		case 11: {
			database.add_order(orders, storages);
			break;
		}
		default:
			std::cout << "bye\n";
			stop = 1;
			break;
		}
	}

}