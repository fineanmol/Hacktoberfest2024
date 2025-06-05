#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int t ;
    cin >> t ;

    while(t--)
    {
    int n , k ;
    cin >> n >> k;
    vector<int> arr(n) ;

    int gov_price = 0 ,total =0 ;

    for(int i=0 ;i<n ; i++ )
    {
        cin>>arr[i] ;
        total+=arr[i] ;
        if(arr[i]> k)
            gov_price+=k ;
        else   
            gov_price += arr[i]  ; 
    }
    cout<<total - gov_price<<"\n";
    }
}