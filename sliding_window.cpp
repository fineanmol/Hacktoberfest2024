#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n , k ;
    cin>> n>>k;
    vector<int> arr(n);

    for(int i=0 ;i<n ;i++)
    cin>>arr[i] ;

    int sum =0 , min  ;
    for(int i=0 ;i<k ;i++)
        sum+=arr[i] ;
    min = sum ; 
    cout<<sum<<endl ;
    for( int i=k ;i<n;i++ )
        {sum=sum+arr[i]-arr[i-k] ;
          cout<<sum<<endl;
        }
}