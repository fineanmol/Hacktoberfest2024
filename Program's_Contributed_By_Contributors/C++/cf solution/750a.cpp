#include<bits/stdc++.h>
using namespace std;
typedef long long int lli ;
int main()
{
    lli Total=240,Lt,gt,tq,count=0;
    cin>>tq>>gt;
    Lt=240-gt;
   for(lli i=1;i<=tq;i++)
   {
       lli tfn=5*i;
       if(tfn<=Lt)
       {Lt=Lt-tfn; count++;}
       else if(Lt<tfn){break;}

   }
   cout<<count<<endl;

}
