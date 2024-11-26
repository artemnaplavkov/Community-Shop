#include <string>
#include "UserEntrance.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
void UserEntrance(string& Tname, vector<string>& V_pas,vector<string>& V_name,vector<char>& V_rs,string& Tpas,int& userID,char& rs){
    int flag2=0;
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
}
