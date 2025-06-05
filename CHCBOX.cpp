#include<bits/stdc++.h>
int main()
{
    int t ;
    cin >> t ;
    while(t--)
    {
        int n ;
        cin >> n ;
        int arr[n+1] ;
        int maxVal = -1 ;
        for(int i= 1 ; i<= n ;i++)
            {
            cin >> arr[i] ;
            if(maxVal<arr[i])
                maxVal = arr[i] ;
            }
        vector<int>sizes() ;
        int count = 0;
        for(int i=1 ;i<=n ;i++)
        {
            if(arr[i]!=maxVal)
                count++;
            else
            {
                sizes.emplace_back(count)
                count=0 ;
            }
        }  

        if(count!=0) //round vector
            sizes[0] =(sizes[0] + count) ;

        int result =0 ;

        for(int i=0 ;i<sizes.size(); i) 
        result+= max(sizes[i]-n/2+1,0)  ; 

        cout<<result ; 

    }
}