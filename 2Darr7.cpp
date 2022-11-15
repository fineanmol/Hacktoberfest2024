#include"bits/stdc++.h"
using namespace std;

int32_t main()
{
    int n,m; cin>>n>>m;
    int target; cin>>target;
    int arr[n][m];
    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    bool flag = false;
    int r=0,c=n-1;
    while (r<m && c>=0)
    {
        if (arr[r][c]==target)
        {
            flag=true;
        }
        arr[r][c]>target?c--:r++;
    }
    if(flag)
        cout<<"Found.";
    else
    {
        cout<<"Not found";
    }
    

    return 0;
}