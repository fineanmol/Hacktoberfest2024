#include<iostream>
#include<iterator>
#include<bits/stdc++.h>
using namespace std;

int krotate(vector<int> a, int x){
    int r=sizeof(a)/sizeof(int);
    int p=r-1;
    x=x%r;
    for(int i=0;i<x;i++){
        
        int temp=a[p];
        a.pop_back();
        a.insert(a.begin(),temp);
    }
    
}

int main(){
    vector<int> a;
    a={1,3,5,7,9};
    int x=2;
	
    krotate(a,x);
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
}