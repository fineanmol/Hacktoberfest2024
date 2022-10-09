#include<iostream>
using namespace std;
int main()
{  int i,j,r;
   cin>>r;
   for(i=1;i<=r;i++)
   {int k=i;
    for(j=1;j<=(r-i);j++)
      {
        cout<<"  ";
      }
    for(j;j<=r;j++)
     {
       cout<<k<<" ";
       k--;
     }
    k=2;
    for(j;j<=r+i-1;j++)
     {
         cout<<k++<<" ";
     }
     for (j;j<=( 2 *r- 1 );j++)
        {
         cout << " " ;
        }
    cout<<endl;
   }
   return 0;
}
