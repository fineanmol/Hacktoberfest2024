#include<bits/stdc++.h>
using namespace std;
int lsearch(vector<int>v,int n){
    int size=v.size();
    for(int i=0;i<size;i++){
        if(v[i]==n) return (i+1);
    }
    return -1;
}
int main(){
    int x;
    vector<int>elements;
    //for number of terms
    int t;
    cin>>t;
    //now pushing elemnts in vector 
    //in case of array, no need for push_back function
    for(int i=0;i<t;i++){ 
        int z;
        cin>>z;
        elements.push_back(z);
    }
    cin>>x;
    //storing index in int variable
    int i=lsearch(elements,x);
    if(i!=-1) cout<<"found at"<<i<<"\n";
    else cout<<"not found!";
    return 0;
}