#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int main() 
{
    int n,num,index,i;
    cout<<"\nEnter the no of elements in the array : ";
    cin>>n;
    int arr[n];
    cout<<"\nEnter the numbers in the array"<<endl;
    for( i=0;i<n;i++)
        cin>>arr[i];
    cout<<"\nEnter a Number to Search : ";
    cin>>num;
    for( i=0; i<n; i++)
    {
        if(arr[i]==num)
        {
            index = i;
            cout<<"\nElement found at Index "<<index;
            break;
        }
    }
        if(i==n)
         {
            cout<<"Element not found"<<endl;
         }
   
    cout<<endl;
    return 0;
}
        
