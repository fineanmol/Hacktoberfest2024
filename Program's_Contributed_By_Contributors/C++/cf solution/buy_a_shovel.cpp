#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main(){
 int k,r,h=1,i=0,j=1;
 bool b=true;
 cin>>k>>r;

 while(b){
    i++;
    h=k*i;
    if(h%10==0 or h%10==r){
        b=false;
    }
 }
 cout<<i;

return 0;
}
