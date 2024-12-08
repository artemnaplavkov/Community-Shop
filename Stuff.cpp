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
    vector<int> TUOrder;
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
            <<"2-create new warehouse"<<endl//+
            <<"3-add courer"<<endl//+
            <<"4-list of courers"<<endl//+
            <<"5-change status of a user"<<endl//+
            <<"6-time shift"<<endl//+
            <<"7-list of uncomfored orders"<<endl//+
            <<"8-confirm order"<<endl//+
            <<"9-delete order from uncomfired list"<<endl//+
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
            case 2:
                database.add_storage(storages);
                            break;
            case 3: {
                        database.add_courier(couriers, storages);
                        break;
                    }
            case 4: {
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
            case 5:
                ChangeStatus(V_pas,V_name,V_rs);
                break;
            case 6:
                std::cout << "hours=";
                            int hours;
                            std::cin >> hours;
                            time_manager.time_shift(hours, storages, couriers, orders);
                            break;
            case 7:
                UncOrder( UnOrder, UOrder);
                break;
            case 8:
                UncOrder( UnOrder, UOrder);
                database.add_order(orders, storages);
                            break;
            case 9:
                UncOrder( UnOrder, UOrder);
                ROrder(UnOrder,UOrder);
                UnOrder.clear();
                UOrder.clear();
                User_list(V_pas,V_name,V_rs,UnOrder,UOrder);
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
        while(1){
            cout<<"---------------------------------------"<<endl;
            cout<<"1-make an order"<<endl//+
            <<"2-show list of your orders"<<endl
            <<"3-cancel order"<<endl
            <<"4-end programm"<<endl;
            cout<<"---------------------------------------"<<endl;
            cin>>key;
            switch(key){
                case 1:
                    MOrder(UnOrder,UOrder,Tname,Tpas);
                    UnOrder.clear();
                    UOrder.clear();
                    User_list(V_pas,V_name,V_rs,UnOrder,UOrder);
                    break;
                case 2:
                    ShOrder(UnOrder,UOrder,Tname,Tpas);
                    break;
                case 3:
                    DelOrder(UnOrder,UOrder,Tname,Tpas, TUOrder);
                    UnOrder.clear();
                    UOrder.clear();
                    User_list(V_pas,V_name,V_rs,UnOrder,UOrder);
                    break;
                case 4:
                    return 0;
                default:
                    cout<<"Command error"<<endl;
                    break;
            }
        }
    }
    return 0;
}
