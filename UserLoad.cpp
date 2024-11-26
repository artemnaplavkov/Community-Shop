#include <string>
#include "UserLoad.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
void UserLoad(){
    ifstream k("UncOrders.txt");
    if(k.is_open()!=true){
        ofstream MyFile("UncOrders.txt",ios::app);
        MyFile.close();
    }
    k.close();
    ifstream in("User_list.txt");
    if(in.is_open()==false){
        string name;
        string pas;
        cout<<"File not found. Would you like to create it?"<<endl;
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
    in.close();
    }
}
void User_list(vector<string>& V_pas,vector<string>& V_name,vector<char>& V_rs,vector<vector<string>>& UnOrder,vector<string>& UOrder){
    ifstream fs;
    char c;
    string abc,name,pas,kkk,Order;
    char rs;;
    int flag;
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
        for(int i=0;i<=kkk.size();i++){
            c=kkk[i];
            if(i==kkk.size()) Order=Order+' ';
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
        UOrder.clear();
    }
    kk.close();
}
