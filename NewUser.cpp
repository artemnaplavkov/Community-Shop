#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <NewUser.h>
void NewUser(vector<string>& V_pas,vector<string>& V_name,vector<char>& V_rs){
    using namespace std;
    string Tname,Tpas;
    char rs;
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
}
