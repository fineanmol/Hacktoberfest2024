#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter array size"<<endl;
    cin>>n;
    int a[n][n];
    cout<<"Enter numbers"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
     cout<<"Given matrix"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    int sr=0;
    int sc=0;
    int ec=n-1,er=n-1;
    

    while(sr<=er && sc<=ec)
    {
        for(int i=sc; i<=ec;i++)
        {
            cout<<a[sr][i]<<" ";
        }
        sr++;
        for(int i=sr;i<=er;i++)
        {
            cout<<a[i][ec]<<" ";
        }
        ec--;
        if(sr<=er){
        for(int i=ec;i>=sc;i--)
        {
            cout<<a[er][i]<<" ";
        }
        er--;
        }
        if(sc<=ec)
        {
        for(int i=er;i>=sr;i--)
        {
            cout<<a[i][sc]<<" ";
        }
        sc++;
        }
    }

}
