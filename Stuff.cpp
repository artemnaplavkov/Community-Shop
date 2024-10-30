#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdio>

using namespace std;

int main()
{
    int ans;
    char c;
    int flag=0;
    int key;
    string abc;
    string name;
    string Tname;
    string Tpas;
    vector<string> V_name;
    string order;
    vector<string> V_order;
    string pas;
    vector<string> V_pas;
    char rs;
    vector<char> V_rs;
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
    }
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
    rs=0;
    for(int i=0;i<V_name.size();i++){
        cout<<V_name[i]<<endl;
    }
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
        cout<<"1-list of orders"<<endl<<"2-create new gingerbread"<<endl<<"3-change gingerbread"<<"4-list of gingerbreads"<<endl<<"5-create new warehouse"<<endl<<"6-quantity of products in warehouses"<<endl<<"7-add product in warehouse"<<endl<<"8-add courer"<<endl<<"9-list of courers"<<endl<<"10-courer info"<<endl<<"11-sales info"<<endl<<"12-change status of a user"<<endl;
        cin>>key;
        switch(key){
        case 12:
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
        }
    }
    return 0;
}
