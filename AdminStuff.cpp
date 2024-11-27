#include "iostream"
#include "string"
#include "vector"
#include "fstream"
#include "AdminStuff.h"
using namespace std;
void ChangeStatus(vector<string>& V_pas,vector<string>& V_name,vector<char>& V_rs){
    string Tname,Tpas;
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
               break;
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
}
void UncOrder(vector<vector<string>>& UnOrder,vector<string>& UOrder){
    cout<<"+++++++++++++++++++++++"<<endl;
    int flag=0;
    if(UnOrder.size()==0){
        cout<<"No uncomfired orders"<<endl;
        flag=1;
    }
    if(flag==0){
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
    }
}
void ROrder(vector<vector<string>>& UnOrder,vector<string>& UOrder){
    int ans;
    int flag=0;
    cout<<"Enter number of order with one you would like to delete:"<<endl;
    cin>>ans;
    if(ans>UnOrder.size()){
        cout<<"No such number"<<endl;
        flag=1;
    }
    if(flag==0){
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
    }
}
