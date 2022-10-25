
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,arr1[50],j,k,arr2[50],c[50],r;
    cout<<"enter the order of first set A : ";
    cin>>n;
      cout<<"Enter the elements\n";
    for(i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
     cout<<"enter the order of second set B : ";
    cin>>m;
      cout<<"Enter the elements\n";
    for(j=0;j<m;j++)
    {
        cin>>arr2[j];
    } 
    cout<<"Difference A-B :";    
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(arr1[i]==arr2[j])
            break;
        }
        if(j==m)
        {
            cout<< arr1[i]<<" ";
        }
    }               
} 