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
    int n,i,j,b,k,flag;
    cout<<"Enter the number of matrices : ";
    cin>>n;
    int p[n+1];
    int table[n][n];
    cout<<"Enter the dimensions : ";
    for (i=0;i<n+1;i++){
        cin>>p[i];
    }
    for (i=0;i<n;i++){
        table[i][i] = 0;
    }
    for(b=1;b<n;b++){
        for(i=0;i<n-b;i++){
            j = i+b;
            table[i][j] = INT8_MAX;
            for(k=i;k<j;k++){
                table[i][j] = minimum(table[i][j],table[i][k]+table[k+1][j]+p[i]*p[k+1]*p[j+1]);
            }
        }
    }
    cout<<"The minimum number of scalar multiplication are : "<<table[0][n-1]<<endl;
    return 0;
}