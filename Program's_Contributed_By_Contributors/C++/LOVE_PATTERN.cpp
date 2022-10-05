#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl
 
int main()
{
   int n;
   
   cout<<"Enter any number between 1-10"<<endl;
   cin>>n;
   
   for(int j=1;j<=n;j++)
   {
       for(int i=j;i<=n;i++)
       {
           cout<<"  ";
       }
       
       for(int i=1;i<=j;i++)
       {
           cout<<"* ";
       }
       
       for(int i=1;i<=j;i++)
       {
           cout<<"* ";
       }
       
       for(int i=j;i<=n;i++)
       {
           cout<<"  ";
       }
       for(int i=j;i<=n;i++)
       {
           cout<<"  ";
       }
       
       for(int i=1;i<=j;i++)
       {
           cout<<"* ";
       }
       for(int i=1;i<=j;i++)
       {
           cout<<"* ";
       }
       for(int i=j;i<=n;i++)
       {
           cout<<"  " ;
       }
       cout<<endl;
   }
   
   
   int m=n*2+1;
   
   for(int j=1;j<=m;j++)
   {
       for(int i=1;i<=j;i++)
       {
           cout<<"  " ;
       }
       
       for(int i=j;i<=m;i++)
       {
           cout<<"* " ;
       }
       
       for(int i=j;i<=m;i++)
       {
           cout<<"* " ;
       }
       
       for(int i=1;i<=j;i++)
       {
           cout<<"  " ;
       }
       
       cout<<endl;
   }
  return 0;
}
