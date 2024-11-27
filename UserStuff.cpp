#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "UserStuff.h"
using namespace std;
void MOrder(vector<vector<string>>& UnOrder,vector<string>& UOrder,string& Tname,string& Tpas){
    string p;
    char c;
    string Order,Order1;
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
