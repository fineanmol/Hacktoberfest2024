#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main(){
int t;
cin>>t;
for(int i=0;i<t;i++){;
 int n,c1,c2;
 cin>>n;
 int res = n%3;
 if(res==0){
    c1=c2=n/3;
 }
 else if(res==1){
    c1=n/3+1;
    c2=n/3;
 }
 else if(res==2){
    c1=n/3;
    c2=n/3+1;
 }
 cout<<c1<<" "<<c2<<endl;
}
return 0;
}