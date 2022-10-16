#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n , k ,t,temp=0;
    cin >> n ;
    vector<int> arr(n);
    for(auto &x :arr)
      cin >> x ;
      
    std::sort(arr.begin(),arr.end()) ;
    //for(auto x: arr)
   //     cout<<x <<" ";
    //    cout<<endl;
    cin >> k ;
    bool found = false ;
    if(k == 1)
    {
        std::sort(arr.begin(),arr.end(),greater<int>() ) ;
        for(int i = 0 ; i<arr.size()-1; i++)
        {
            if(arr[i]!=arr[i+1])
                {t= arr[i] ; break ;}
        }
    }
    else 
    {
        for(int i = 0 ; i<arr.size()-1; i++) // for k=>2
        {
        if(arr[i]==arr[i+1] && found==false)//A number is found 
            {
                t=arr[i] ;
                found = true ;
                temp++ ;
            }
        else if(arr[i]==arr[i+1] && found==true)
        {
            temp++ ;
        }
        
        else if(arr[i]!=arr[i+1] && found==true)
        {
            if(temp == k-1) //exect match
            {
                break;
            }
            else
            {
                temp = 0 ;
            }
        }  
        else if (i==n-2 && arr[i]==arr[i+1]) //chehk value at end
        {
            t=arr[i] ;
            temp++ ;
        }  
        }
    }
    cout<<t <<"\n" ;
    return 0;
}