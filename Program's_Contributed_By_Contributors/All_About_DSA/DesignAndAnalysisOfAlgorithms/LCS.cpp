#include <iostream>
using namespace std;

int max(int a,int b){
    if (a>b){
        return a;
    }
    else{
        return b;
    }
}

int main(){
    string x,y,result;
    int m,n,i,j;
    cout<<"Enter the first string : ";
    cin>>x;
    cout<<"Enter the second string : ";
    cin>>y;
    result="\0";
    m = x.length();
    n = y.length();
    int table[m+1][n+1];
    for (i=0;i<m+1;i++){
        table[i][0] = 0;
    }
    for (j=0;j<n+1;j++){
        table[0][j] = 0;
    }
    for (i=1;i<m+1;i++){
        for (j=1;j<n+1;j++){
            if (x.at(i-1)==y.at(j-1)){
                table[i][j] = 1+table[i-1][j-1];
            }
            else{
                table[i][j] = max(table[i][j-1],table[i-1][j]);
            }
        }
    }
    for (i=0;i<m+1;i++){
        for (j=0;j<n+1;j++){
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    i = m;
    j = n;
    while ((i>0)&&(j>0)){
        if (x.at(i-1)==y.at(j-1)){
            result = x.at(i-1)+result;
            i = i-1;
            j = j-1;
        }
        else if (table[i-1][j]>table[i][j-1]){
            i = i-1;
        }
        else{
            j = j-1;
        }
    }   
    cout<<"Longest Common Subsequence is : "<<result<<endl;
    return 0;
}