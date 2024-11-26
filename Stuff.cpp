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

using namespace std;

int main()
{
    std::vector<abstracts::Storage> storages;
    std::vector<abstracts::Courier> couriers;
    std::vector<abstracts::Order> orders;
    DatabaseManager database;
    TimeManager time_manager;

    int ans;
    char c;
    int flag=0;
    int key;
    string kkk;
    string p;
    string Order;
    string Order1;
    string abc;
    string name;
    string Tname;
    string Tpas;
    vector<vector<string>> UnOrder;
    vector<string> UOrder;
    vector<string> V_name;
    string order;
    vector<string> V_order;
    string pas;
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
            <<"13-list og uncomfored orders"<<endl//+
            <<"14-confirm order"<<endl//+
            <<"15-delete order from uncomfired list"<<endl
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
                cout<<"+++++++++++++++++++++++"<<endl;
                if(UnOrder.size()==0){
                    cout<<"No uncomfired orders"<<endl;
                    continue;
                }
                cout<<"List of uncomfirmed orders:"<<endl;
                for(int i=0;i<UnOrder.size();i++){
                    UOrder=UnOrder[i];
                    cout<<"Name: "<<UOrder[0]<<endl;
                    cout<<"Password: "<<UOrder[1]<<endl;
                    for(int j=2;j<UOrder.size()-2;j++){
                        cout<<UOrder[j]<<" ";
                    }
                    cout<<endl<<"x="<<UOrder[UOrder.size()-2];
                    cout<<endl<<"y="<<UOrder[UOrder.size()-1]<<endl;
                }
                cout<<"+++++++++++++++++++++++"<<endl;
                break;
            case 14:
                cout<<"+++++++++++++++++++++++"<<endl;
                if(UnOrder.size()==0){
                    cout<<"No uncomfired orders"<<endl;
                    continue;
                }
                cout<<"List of uncomfirmed orders:"<<endl;
                for(int i=0;i<UnOrder.size();i++){
                    UOrder=UnOrder[i];
                    cout<<"Name: "<<UOrder[0]<<endl;
                    cout<<"Password: "<<UOrder[1]<<endl;
                    for(int j=2;j<UOrder.size()-2;j++){
                        cout<<UOrder[j]<<" ";
                    }
                    cout<<endl<<"x="<<UOrder[UOrder.size()-2];
                    cout<<endl<<"y="<<UOrder[UOrder.size()-1]<<endl;
                }
                cout<<"+++++++++++++++++++++++"<<endl;
                database.add_order(orders, storages);
                            break;
            case 15:
                cout<<"+++++++++++++++++++++++"<<endl;
                if(UnOrder.size()==0){
                    cout<<"No uncomfired orders"<<endl;
                    continue;
                }
                cout<<"List of uncomfirmed orders:"<<endl;
                for(int i=0;i<UnOrder.size();i++){
                    UOrder=UnOrder[i];
                    cout<<"Name: "<<UOrder[0]<<endl;
                    cout<<"Password: "<<UOrder[1]<<endl;
                    for(int j=2;j<UOrder.size()-2;j++){
                        cout<<UOrder[j]<<" ";
                    }
                    cout<<endl<<"x="<<UOrder[UOrder.size()-2];
                    cout<<endl<<"y="<<UOrder[UOrder.size()-1]<<endl;
                }
                cout<<"+++++++++++++++++++++++"<<endl;
                cout<<"Enter number of order with one you would like to delete:"<<endl;
                cin>>ans;
                if(ans>UnOrder.size()){
                    cout<<"No such numder"<<endl;
                    break;
                }
                remove("UncOrders.txt");
                for(int i=0;i!=ans;i++){
                    UOrder==UnOrder[i];
                    ofstream MyFile("UncOrders.txt",ios::app);
                    for(int i=0;i<UOrder.size();i++){
                        MyFile<<UOrder[i];
                        MyFile<<' ';
                    }
                    MyFile<<endl;;
                    MyFile.close();
                }
                for(int i=ans+1;i<UnOrder.size();i++){
                    UOrder==UnOrder[i];
                    ofstream MyFile("UncOrders.txt",ios::app);
                    for(int i=0;i<UOrder.size();i++){
                        MyFile<<UOrder[i];
                        MyFile<<' ';
                    }
                    MyFile<<endl;;
                    MyFile.close();
                }
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
        cout<<"1-make an order"<<endl<<"2-check order status"<<endl<<"3-show list of your orders"<<endl<<"4-cancel order"<<endl;
        cin>>key;
        switch(key){
            case 1:
                UOrder.clear();
                UOrder.push_back(Tname);
                UOrder.push_back(Tpas);
                cout<<"Enter your order(enter separated by commas):"<<endl;
                cin>>Order;
                Order=Order+',';
                for(int i=0;i<Order.size();i++){
                    c=Order[i];
                    if(c!=','){
                        Order1.push_back(c);
                    }
                    else{
                        UOrder.push_back(Order1);
                        Order1.clear();
                    }
                }
                cout<<"Enter your coordinates:"<<endl<<"X=";
                cin>>p;
                UOrder.push_back(p);
                cout<<"Y=";
                cin>>p;
                UOrder.push_back(p);
                ofstream MyFile("UncOrders.txt",ios::app);
                for(int i=0;i<UOrder.size();i++){
                    MyFile<<UOrder[i];
                    MyFile<<' ';
                }
                MyFile<<endl;;
                MyFile.close();
        }
    }
    return 0;
}
