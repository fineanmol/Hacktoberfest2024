#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;

int chk(ll x){
    ll num=(x*(x+1))/2;
    if(num>m)
    return 0;
return 1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        ll lo=0,hi=2000000000,pos=0;
        ll mid=lo+hi/2;
        while (hi>=lo)
        {
            mid=(lo+hi)/2;
            if(chk(mid)){
                pos=mid;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        ll num=(pos*(pos+1))/2;
        cout<<m-num<<endl;
    }
    return 0;
}