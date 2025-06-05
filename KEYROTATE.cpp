#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long Search(vector<long> arr ,long l,long r,long x)
{
    if(l > r )
        return -1 ;

    long mid = l+(r-l)/2 ;

    if(arr[mid] == x)
        return mid ;

    else if(arr[mid]<x)
        return Search(arr,mid+1,r,x) ;

    else  
        return Search(arr,l,mid-1,x) ;      
}

long findPivot(vector<long>arr, long low, long high)
{
    // Base cases
    if (high < low)
        return -1;
    if (high == low)
        return low;
 
    // low + (high - low)/2;
    long mid = (low + high) / 2;
    if (mid < high && arr[mid] > arr[mid + 1])
        return mid;
 
    if (mid > low && arr[mid] < arr[mid - 1])
        return (mid - 1);
 
    if (arr[low] >= arr[mid])
        return findPivot(arr, low, mid - 1);
 
    return findPivot(arr, mid + 1, high);
}
int main()
{
    int t;
    cin >> t;

    while(t--)
    {
      long n , x ,ans;
      
      long pivot  ;
      
      cin>> n ;
      vector<long> arr(n) ;
      
      for(int i=0 ;i<n; i++)
      {
        cin>>arr[i] ;
      }
      cin>>x ;

      pivot =findPivot(arr,0,n-1) ;
      //cout<<"PIVOT = "<<pivot<<"\n" ;
      
    if(pivot==-1) // no rotation
        ans = Search(arr,0,n-1,x) ;

    else if(arr[pivot]==x)
        ans= pivot ;
    else
        {
            if(x>=arr[0])
               ans= Search(arr,0,pivot-1,x) ;
            else ans=Search(arr,pivot+1,n-1,x) ;    
        }

    cout<<ans<<"\n" ; 


    }
}
/*
My method
int main()
{
    int t;
    cin >> t;

    while(t--)
    {
      long n , x ,ans;
      
      long big= 0, ind = -1 ;
      
      cin>> n ;
      vector<long> arr(n) ;
      
      for(int i=0 ;i<n; i++)
      {
        cin >>arr[i] ;
        if(arr[i]>big)
        {
          big = arr[i] ;
          ind = i ;
        }
      }
      sort(arr.begin(),arr.end()) ;
      cin>>x;
      ans =Search(arr,0,n-1,x) ;
     

      if(ans==-1) cout<<-1 ;
      
      else
      {
      ans=ans-n+ind+1 ;

      cout<<ans<<"\n" ;
      }
    }
    return 0;
}
*/