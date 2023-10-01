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
    int n,m,i,j,k;
    cout<<"Enter the number of vertices : ";
    cin>>n;
    cout<<"Enter the number of edges : ";
    cin>>m;
    int table[n][n];
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            table[i][j] = 214748364;
        }
    }
    for (i=0;i<n;i++){
        table[i][i] = 0;
    }
    int a,b;
    for (i=0;i<m;i++){
        cout<<"Enter the edge : ";
        cin>>a>>b;
        cout<<"Enter the weight : ";
        cin>>table[a-1][b-1];
    }
    for (k=0;k<n;k++){
        for (i=0;i<n;i++){
            for (j=0;j<n;j++){
                if ((i!=k)&&(j!=k)){
                    table[i][j] = minimum(table[i][j],table[i][k]+table[k][j]);
                }
            }
        }
    }
    cout<<"Shortest Path from every path to every path : "<<endl;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}