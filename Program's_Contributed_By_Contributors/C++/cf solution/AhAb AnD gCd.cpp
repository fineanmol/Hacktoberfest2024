#include<iostream>
#include<bits/stdc++.h>

using namespace std;
void solve(int n){
    for(int i=1;i<n;i++){
        int a=i;
        int b=n-i;
    int ans1=__gcd(a,b);
    int ans2=lcm(a,b);
    if(ans1+ans2==n){
        cout<<a<<" "<<b<<endl;
        break;
    }

    }
}
int main(){
int t;
cin>>t;
for(int i=0;i<t;i++){;
 int x;
 cin>>x;
solve(x);
}
return 0;
}