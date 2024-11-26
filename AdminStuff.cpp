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
