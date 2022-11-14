#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main(){
int t;
cin>>t;
for(int i=0;i<t;i++){;
 int a,b;
 cin>>a>>b;
 int res= min(min(a,b),(a+b)/4);
 cout<<res<<endl;
}
return 0;
}