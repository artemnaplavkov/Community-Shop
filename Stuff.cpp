#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdio>
#include "courier.h"
#include "order.h"
#include "storage.h"
#include "time_manager.h"
#include "database_manager.h"
#include "UserLoad.h"
#include "NewUser.h"
#include "UserEntrance.h"
#include "AdminStuff.h"
#include "UserStuff.h"

using namespace std;

int main()
{
    std::vector<abstracts::Storage> storages;
    std::vector<abstracts::Courier> couriers;
    std::vector<abstracts::Order> orders;
    DatabaseManager database;
    TimeManager time_manager;
    int key;
    string Tname;
    string Tpas;
    vector<vector<string>> UnOrder;
    vector<string> UOrder;
    vector<string> V_name;
    vector<string> V_order;
    vector<string> V_pas;
    char rs;
    vector<char> V_rs;
    UserLoad();
    User_list(V_pas,V_name,V_rs,UnOrder,UOrder);
    rs=0;
    cout<<"Enter your name(If you don't have account enter: new): "<<endl;
    cin>>Tname;
    if(Tname=="new"){
        NewUser(V_pas,V_name,V_rs);
        return 0;
    }
    cout<<"Enter your password: "<<endl;
    cin>>Tpas;
    int userID;
    UserEntrance(Tname, V_pas, V_name,V_rs,Tpas, userID,rs);
    if(rs=='1'){
        while(1){
            cout<<"---------------------------------------"<<endl
            <<"1-list of confirmed orders"<<endl//+
            <<"2-create new gingerbread"<<endl
            <<"3-change gingerbread"<<endl
            <<"4-list of gingerbreads"<<endl
            <<"5-create new warehouse"<<endl//+
            <<"6-quantity of products in warehouses"<<endl
            <<"7-add product in warehouse"<<endl
            <<"8-add courer"<<endl//+
            <<"9-list of courers"<<endl//+
            <<"10-sales info"<<endl
            <<"11-change status of a user"<<endl//+
            <<"12-time shift"<<endl//+
            <<"13-list of uncomfored orders"<<endl//+
            <<"14-confirm order"<<endl//+
            <<"15-delete order from uncomfired list"<<endl//+
            <<"---------------------------------------"<<endl;
            cin>>key;
            switch(key){
            case 1:
                std::cout << "orders:\n";
                           for (int i = 0; i < orders.size(); i++) {
                               if (orders[i].state != abstracts::completed) {
                                   orders[i].print();
                                   std::cout << "\n";
                               }
                           }
                           break;
            case 5:
                database.add_storage(storages);
                            break;
            case 8: {
                        database.add_courier(couriers, storages);
                        break;
                    }
            case 9: {
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
            case 11:
                ChangeStatus(V_pas,V_name,V_rs);
                break;
            case 12:
                std::cout << "hours=";
                            int hours;
                            std::cin >> hours;
                            time_manager.time_shift(hours, storages, couriers, orders);
                            break;
            case 13:
                UncOrder( UnOrder, UOrder);
                break;
            case 14:
                UncOrder( UnOrder, UOrder);
                database.add_order(orders, storages);
                            break;
            case 15:
                UncOrder( UnOrder, UOrder);
                ROrder(UnOrder,UOrder);
                break;
            default:
                cout<<"Command error"<<endl;
                break;
            }
            database.save(storages);
            database.save(couriers);
            database.save(orders);
        }
    }
    if(rs=='0'){
        cout<<"---------------------------------------"<<endl;
        cout<<"1-make an order"<<endl//+
        <<"2-check order status"<<endl
        <<"3-show list of your orders"<<endl
        <<"4-cancel order"<<endl;
        cout<<"---------------------------------------"<<endl;
        cin>>key;
        switch(key){
            case 1:
                MOrder(UnOrder,UOrder,Tname,Tpas);
                break;
            default:
                cout<<"Command error"<<endl;
                break;
        }
    }
    return 0;
}
