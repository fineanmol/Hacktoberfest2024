#include<iostream>
using namespace std;
#include<vector>
int main()
{
    int t ;
    int n ;
    int s ;
    cin>> t ;

    while(t--)
    {
       
        cin >> n >> s;
        int min1 = 10000 , min2=10000 ;
        vector<int> p(n) , pos(n) ;
        for(int i = 0 ;i < n ;i++)
            {
                cin >> p[i] ; 
            }

        for(int i=0 ;i<n;i++)
            {
                cin >> pos[i] ;

            } 
        for(int i=0 ;i<n;i++)
            {
                if(pos[i]==0)
                {
                    if(p[i]<min1)
                         min1=p[i] ;
                }
                else 
                {
                    if(p[i]<min2)
                    min2=p[i] ;
                }
            }
            if(min1+min2<=100-s)
                cout<<"yes\n" ;
            else 
                cout<<"no\n" ;    

    }
}