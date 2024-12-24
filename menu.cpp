#include "courier.h"
#include "order.h"
#include "storage.h"
#include "time_manager.h"

#include "menu.h"
#include "database_manager.h"
#include <sstream>
#include <vector>

using namespace std;

void menu(Socket& socket) {

	vector<abstracts::Storage> storages;
	vector<abstracts::Courier> couriers;
	vector<abstracts::Order> orders;
	DatabaseManager database;
	TimeManager time_manager;


	string str;
	while (true){
		ostringstream os;
		os
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
			<< "\n11-add order";
		socket.set(str + os.str());
		str.clear();
		int key = atoi(socket.get().data());
		switch (key) {
			
		case 1:
			database.save(storages);
			database.save(couriers);
			database.save(orders);
			break;
		case 2:
			database.read(storages);
			database.read(couriers);
			database.read(orders);
			break;
		case 3: {
			socket.set("hours=");
			int hours = atoi(socket.get().data());
			time_manager.time_shift(hours, storages, couriers, orders);
			break; //time skip
		}
		case 4: {
			ostringstream os;
			os << "storages:\n";
			for (int i = 0; i < storages.size(); i++) {
				storages[i].print();
				os << "\n";
			}
			str = os.str();
			break;
		}
		
		case 5: {
			str = database.add_storage(storages, socket);
			break;
	
		}
		case 6: {
			socket.set("removing storage id=");
			int id = atoi(socket.get().data());
			str = database.remove_storage(storages, couriers, orders, id);
			break;
		}
		case 7: {
			socket.set("couriers from storage id=");
			int storage_id = atoi(socket.get().data());
			ostringstream os;
			for (int i = 0; i < couriers.size(); i++) {
				if (couriers[i].storage_id == storage_id) {
					os<<couriers[i].print() << "\n";
				}
			}
			str = os.str();
			break;
		}
			  
		case 8: {
			str = database.add_courier(couriers, storages, socket);
			break;
		}

		case 9: {
			socket.set("removing courier id=");
			int id = atoi(socket.get().data());
			str = database.remove_courier(couriers, id);
			break;
		}
		case 10: {
			ostringstream os;
			os << "orders:\n";
			for (int i = 0; i < orders.size(); i++) {
				if (orders[i].state != abstracts::completed) {
					os << orders[i].print() << "\n";
				}
			}
			str = os.str();
			break;
		}
		case 11: {
			str = database.add_order(orders, storages, socket);
			break;
		}
		default:
			socket.set("exit");
			return;
		}
	}

}
