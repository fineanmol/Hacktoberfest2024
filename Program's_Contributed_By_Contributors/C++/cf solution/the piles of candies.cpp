#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main(){
int t;
cin>>t;
for(int i=0;i<t;i++){;
 long long int a,b,c;
 cin>>a>>b>>c;
 long long int total= a+b+c;
 if(total%2==0){
    cout<<total/2<<endl;
 }
 else{
    cout<<(total-1)/2<<endl;
 }

}
return 0;
}