

#include<bits/stdc++.h>
using namespace std;


int subset_sum(int arr[],int n,int range)
{
    bool t[n+1][range+1];
    int i,j;

    for(i=0;i<n+1;i++)
    {
        for(j=0;j<range+1;j++)
        {
            if(i==0)
                t[i][j]=false;
            
            if(j==0)
                t[i][j]=true;

        }
    }

    for(i=1;i<n+1;i++)
    {
        for(j=1;j<range+1;j++)
        {
            if(arr[i-1]<=j)
                t[i][j]= t[i-1][j] || t[i-1][j-arr[i-1]];
            else
                t[i][j]=t[i-1][j];
        }
    }

    
    for(i=range/2;i>=0;i--)
    {
        if(t[n][i]==true)
            return range-2*i;
    }

    return 0;
}



int main()
{
    int i,n,arr[10],sum=0;
    cout<<"\nEnter the size\n";
    cin>>n;
    cout<<"\nEnter the Array\n";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }

    cout<<"\nAnswer is - "<<subset_sum(arr,n,sum);
    
    return 0;
}
