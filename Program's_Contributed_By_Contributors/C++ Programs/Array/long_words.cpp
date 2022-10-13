#include<bits/stdc++.h>
#include<iostream>
#include<string>

using namespace std;

void sol(vector<string> str){
    for(int i=0;i<str.size();i++){
    if(str[i].size()>10){
    cout<<str[i].front()<<(str[i].size()-2)<<str[i].back()<<endl;
    }else{
        cout<<str[i]<<endl;
    }
    }
}

int main(){
    int t;
    string str1;
    vector<string> str;
    cin>>t;
    while(t){
        cin>>str1;
        str.push_back(str1);
    --t;
}
    sol(str);
    return 0;
}
