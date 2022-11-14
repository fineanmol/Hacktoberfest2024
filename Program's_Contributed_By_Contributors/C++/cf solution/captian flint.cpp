#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void solve(int n){
    int rem1= n-16;
    if(n<=30){
        cout<<"NO"<<endl;
    }
    else{
        int d1=2*7;
        int d2=3*5;
        int d3=3*7;
        int d4=2*11;
        int rem2=rem1-d1;
        int rem3=rem1-d2;
        int rem4=rem1-d3;
        int rem5=rem1-d4;
        if(rem2>0 and rem2!=d1  and rem2!= 6 and rem2!=10){
            cout<<"YES"<<endl;
            cout<<6<<" "<<10<<" "<<d1<<" "<<rem2<<endl;
        }
        else if(rem3>0 and rem3!=d2  and rem3!= 6 and rem3!=10){
            cout<<"YES"<<endl;
            cout<<6<<" "<<10<<" "<<d2<<" "<<rem3<<endl;
        }
        else if(rem4>0 and rem4!=d3  and rem4!= 6 and rem4!=10){
            cout<<"YES"<<endl;
            cout<<6<<" "<<10<<" "<<d3<<" "<<rem4<<endl;
        }
        else if(rem5>0 and rem5!=d4  and rem5!= 6 and rem5!=10){
            cout<<"YES"<<endl;
            cout<<6<<" "<<10<<" "<<d4<<" "<<rem5<<endl;
        }
    }
}
int main(){
int t;
cin>>t;
for(int i=0;i<t;i++){;
 int n;
 cin>>n;
 solve(n);
}
return 0;
}