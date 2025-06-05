#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int t ;
    cin >> t;
    while(t--)
    {
        int n , a;
        cin >> n;
        vector<int> arr ;
        for(int i=0 ;i< n ;i++)
        {
            cin >> a ;
            if(a==1)
                arr.push_back(i) ;
        }
        int flag = 0 ;
        for(int i=arr.size()-1 ; i>0;i--)
        {
            int s = arr[i] -arr[i-1] ;
            if(s<6)
            {
                cout<<"NO\n" ;
                flag+=1;
                break ;
            }
        }
        if(flag == 0) //no change
            cout<<"YES\n" ;
    }
}