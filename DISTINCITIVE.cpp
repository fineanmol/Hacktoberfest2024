#include<iostream>
#include<cstring>
using namespace std ;
int main()
{
    int t ;
    cin >> t;
    while(t--)
    {
    int n;
    string s;
    int count[26]  ;

    for (int i = 0; i<26 ;i++)
        count[i] =0 ;
    //cout<< int('z')-97; 25
    
    cin >> s ;
    n =s.size();

  //cout<<n ;
    
    for(int i=0 ; i<n ; i++)
        count[s[i]-97]++;

    int flag = 0 ;
    for(int i=0 ; i<n ; i++)
    {
        if( count[s[i]-97] == 1 )
        {
            cout<<i<<endl ;
            flag = 1 ;
            break ;
        }
    }
    if (flag == 0)
        cout << -1<<endl ;
    }
}