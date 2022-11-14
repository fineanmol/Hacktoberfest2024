#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    string n=;
    cin>>n;
    int i=0;
    int v=0;
    int sign=1;
    if(n[i]=='-'){
        sign=-1;
        i++;
    }
    for(; i<n.size(); i++){
        v=v*10+n[i]-'0';
    }
    cout<<v*sign;
    return 0;
}
