#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main(){
int t;
cin>>t;
string comp="yes";
for(int i=0;i<t;i++){;
 string s;
 cin>>s;

 transform(s.begin(), s.end(), s.begin(), ::tolower);

 if(s==comp){
    cout<<"YES"<<endl;
 }
 else{
    cout<<"NO"<<endl;
 }
}
return 0;
}