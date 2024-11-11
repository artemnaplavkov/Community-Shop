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
    ifstream k("UncOrders.txt");
    if(k.is_open()!=true){
        ofstream MyFile("UncOrders.txt",ios::app);
        MyFile.close();
    }
    k.close();
    ifstream in("User_list.txt");
    if(in.is_open()==false){
        cout<<"File not found. Would you like to create it?"<<endl;
        cout<<"1-yes"<<endl;
        cout<<"2-no"<<endl;
        cin>>ans;
        if(ans==1){
            ofstream MyFile("User_list.txt",ios::app);
            cout<<"File successfully created"<<endl;
            cout<<"Name and password should be without space"<<endl;
            cout<<"Enter admin name: "<<endl;
            cin>>name;
            cout<<"Enter admin password: "<<endl;
            cin>>pas;
            MyFile<<name;
            MyFile<<' ';
            MyFile<<pas;
            MyFile<<' ';
            MyFile<<1<<endl;
            MyFile.close();
        }
        else{
            cout<<"File error"<<endl;
        }
        return 0;
    };
    in.close();
    ifstream fs;
    fs.open("User_list.txt");
    while(getline(fs, abc)){
        for(int i=0;i<abc.size();i++){
            c=abc[i];
            if(c!=' ' && flag==0){
                name.push_back(c);
            }
            if(c!=' ' && flag==1){
                pas.push_back(c);
            }
            if(flag==2){
                rs=c;
                break;
            }
            if(c==' ' && flag==1) flag=2;
            if(c==' ' && flag==0) flag=1;
        }
        flag=0;
        V_pas.push_back(pas);
        V_name.push_back(name);
        V_rs.push_back(rs);
        pas.clear();
        name.clear();
    };
    fs.close();
    ifstream kk;
    kk.open("UncOrders.txt");
    while(getline(kk,kkk)){
        for(int i=0;i<kkk.size();i++){
            c=kkk[i];
            if(c!=' '){
                Order.push_back(c);
            }
            else{
                UOrder.push_back(Order);
                Order.clear();
                continue;
            }
        }
        UnOrder.push_back(UOrder);
    }
    kk.close();
    rs=0;
    /*for(int i=0;i<V_name.size();i++){
        cout<<V_name[i]<<endl;
    }*/
    cout<<"Enter your name(If you don't have account enter: new): "<<endl;
    cin>>Tname;
    if(Tname=="new"){
        cout<<"Enter your name:"<<endl;
        cin>>Tname;
        cout<<"Enter your password: "<<endl;
        cin>>Tpas;
        V_pas.push_back(Tpas);
        V_name.push_back(Tname);
        V_rs.push_back(rs);
        ofstream MyFile("User_list.txt",ios::app);
        MyFile<<Tname;
        MyFile<<' ';
        MyFile<<Tpas;
        MyFile<<' ';
        MyFile<<0<<endl;
        MyFile.close();
        return 0;
    }
    cout<<"Enter your password: "<<endl;
    cin>>Tpas;
    int flag2=0;
    int userID;
    for(int i=0;i<V_name.size();i++){
        if(V_name[i]==Tname && V_pas[i]==Tpas){
           cout<<"Welcome "<<Tname<<endl;
           rs=V_rs[i];
           flag2=1;
           userID=i;
           break;
        }
    };
    if(flag2==0) cout<<"Name or password error"<<endl;
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
                cout<<"Enter user name: "<<endl;
                cin>>Tname;
                cout<<"Enter user password: "<<endl;
                cin>>Tpas;
                for(int i=0;i<V_name.size();i++){
                    if(V_name[i]==Tname && V_pas[i]==Tpas){
                       cout<<"Found: "<<V_name[i]<<" "<<V_pas[i]<<" "<<V_rs[i]<<endl;
                       cout<<"Should this user 1-admin or 2-ordinary user"<<endl;
                       int a;
                       cin>>a;
                       if(a==1){
                           V_rs[i]='1';
                       }
                       else if(a==2){
                           V_rs[i]='0';
                       }
                       else{
                           cout<<"Command error"<<endl;
                           return 0;
                       }
                       if(remove("User_list.txt")==true) cout<<"123"<<endl;
                       for(int i=0;i<V_name.size();i++){
                           ofstream MyFile("User_list.txt",ios::app);
                           MyFile<<V_name[i];
                           MyFile<<' ';
                           MyFile<<V_pas[i];
                           MyFile<<' ';
                           MyFile<<V_rs[i]<<endl;
                           MyFile.close();
                       }
                       break;
                    }
                };
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
                    UOrder==UnOrder[i];
                    for(int j=0;j<UOrder.size();j++){
                        if(j<UOrder.size()-2) cout<<UOrder[j]<<" ";
                        if(j==UOrder.size()-2) cout<<endl<<"X="<<UOrder[j]<<endl;
                        if(j==UOrder.size()-1) cout<<"Y="<<UOrder[j]<<endl;
                    }
                    if(i!=UnOrder.size()-1) cout<<"-----------------------"<<endl;
                }
                cout<<"+++++++++++++++++++++++"<<endl;
            case 14:
                cout<<"+++++++++++++++++++++++"<<endl;
                if(UnOrder.size()==0){
                    cout<<"No uncomfired orders"<<endl;
                    continue;
                }
                cout<<"List of uncomfirmed orders:"<<endl;
                for(int i=0;i<UnOrder.size();i++){
                    UOrder==UnOrder[i];
                    for(int j=0;j<UOrder.size();j++){
                        if(j<UOrder.size()-2) cout<<UOrder[j]<<" ";
                        if(j==UOrder.size()-2) cout<<endl<<"X="<<UOrder[j]<<endl;
                        if(j==UOrder.size()-1) cout<<"Y="<<UOrder[j]<<endl;
                    }
                    if(i!=UnOrder.size()-1) cout<<"-----------------------"<<endl;
                }
                cout<<"+++++++++++++++++++++++"<<endl;
                database.add_order(orders, storages);
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
                cout<<"Enter your order(enter separated by commas):"<<endl;
                cin>>Order;
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
                cout<<endl<<"Y=";
                cin>>p;
                UOrder.push_back(p);
                ofstream MyFile("UncOrders.txt",ios::app);
                for(int i=0;i<UOrder.size();i++){
                    MyFile<<UOrder[i];
                    MyFile<<' ';
                }
                MyFile.close();
        }
    }
    return 0;
}
