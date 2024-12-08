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
        if(i!=UOrder.size()-1) MyFile<<' ';
    }
    MyFile<<endl;;
    MyFile.close();
}
void ShOrder(vector<vector<string>>& UnOrder,vector<string>& UOrder,string& Tname,string& Tpas){
    int flag=0;
    int h=0;
    cout<<"+++++++++++++++++++++++"<<endl;
    for(int i=0;i<UnOrder.size();i++){
        UOrder=UnOrder[i];
        if(UOrder[0]==Tname && UOrder[1]==Tpas){
            h++;
            flag=1;
            cout<<h<<")";
            cout<<"Name: "<<UOrder[0]<<endl;
            cout<<"Password: "<<UOrder[1]<<endl;
            for(int j=2;j<UOrder.size()-2;j++){
                cout<<UOrder[j]<<" ";
            }
            cout<<endl<<"x="<<UOrder[UOrder.size()-2];
            cout<<endl<<"y="<<UOrder[UOrder.size()-1]<<endl;
        }
    }
    if(flag==0) cout<<"There is no your orders or courer already take it"<<endl;
    cout<<"+++++++++++++++++++++++"<<endl;
}
void DelOrder(vector<vector<string>>& UnOrder,vector<string>& UOrder,string& Tname,string& Tpas, vector<int>& TUOrder){
    int flag=0;
    int ans;
    int h=0;
    cout<<"+++++++++++++++++++++++"<<endl;
    for(int i=0;i<UnOrder.size();i++){
        UOrder=UnOrder[i];
        if(UOrder[0]==Tname && UOrder[1]==Tpas){
            TUOrder.push_back(i);
            h++;
            cout<<h<<")";
            flag=1;
            cout<<"Name: "<<UOrder[0]<<endl;
            cout<<"Password: "<<UOrder[1]<<endl;
            for(int j=2;j<UOrder.size()-2;j++){
                cout<<UOrder[j]<<" ";
            }
            cout<<endl<<"x="<<UOrder[UOrder.size()-2];
            cout<<endl<<"y="<<UOrder[UOrder.size()-1]<<endl;
        }
    }
    if(flag==0) cout<<"There is no your orders or courer already take it"<<endl;
    else{
        flag=0;
        cout<<"Enter number of order with one you would like to delete:"<<endl;
        cin>>ans;
        if(ans>TUOrder.size()){
            cout<<"No such number"<<endl;
            flag=1;
        }
        if(TUOrder.size()==0){
            flag=1;
        }
        ans=TUOrder[ans-1];
        if(flag==0){
            remove("UncOrders.txt");
            ofstream MyFile("UncOrders.txt",ios::app);
            for(int i=0;i<ans;i++){
                UOrder=UnOrder[i];
                for(int i=0;i<UOrder.size();i++){
                    MyFile<<UOrder[i];
                    if(i!=UOrder.size()-1) MyFile<<' ';
                }
                MyFile<<endl;;
            }
            for(int i=ans+1;i<UnOrder.size();i++){
                UOrder=UnOrder[i];
                for(int i=0;i<UOrder.size();i++){
                    MyFile<<UOrder[i];
                    if(i!=UOrder.size()-1) MyFile<<' ';
                }
                MyFile<<endl;
            }
            MyFile.close();
        }
    }
    cout<<"+++++++++++++++++++++++"<<endl;

}
