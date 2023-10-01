#include <iostream>
using namespace std;

int minimum(int a,int b){
    if (a<b){
        return a;
    }
    else{
        return b;
    }
}

int main(){
    int n,m,i,j;
    cout<<"Enter the number of vertices : ";
    cin>>n;
    cout<<"Enter the number of edges : ";
    cin>>m;
    int d[n],prev[n];
    int u[m],v[m],w[m];
    d[0] = 0;
    prev[0] = 0;
    for(i=1;i<n;i++){
        d[i] = 214748364;
        prev[i] = -1;
    }
    for(i=0;i<m;i++){
        cout<<"Enter the edge : ";
        cin>>u[i]>>v[i];
        cout<<"Enter the weight : ";
        cin>>w[i];
    }
    for(j=0;j<n-1;j++){
        for(i=0;i<m;i++){
            
        }
    }
}