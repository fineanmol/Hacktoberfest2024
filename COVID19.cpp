#include<bits/stdc++.h>
using namespace std ;
int main()
{
int n,t ;
cin>>t ;
while(t--)
{
cin >> n ;
vector<int> arr(n) ;
vector<int> diff ;

for(int i=0 ;i< n ;i++)
    cin >> arr[i] ;

for(int i = 1;i<n ;i++)
    diff.push_back(arr[i]-arr[i-1]) ;

int count=0 ;
int minv =100 , maxv = -1 ;

for(int i =0 ;i<diff.size(); ++i)
{
    if(diff[i]<=2)
    {
        count++ ;
    }
    if(minv>count)
        min = count ;
    if(maxv<count)
        maxv = count ;
        count = 1 ;
}
if(minv>count)
        minv = count ;
if(maxv<count)
        maxv = count ;
count <<minv<<" "<<maxv<<"\n" ;
}

}