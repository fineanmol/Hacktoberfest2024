#include <iostream>
#include <string>
using namespace std;
void increment(int  x, int* y)
{   x=x+1;  
   *y=*y+1;
}
int main()
{
   int a=5, b=6;
   increment(a,&b);
   cout<<endl;
   cout<<"New values"<<endl;
   cout<<"a = "<<a<<"\t"<<"b = "<<b;
   return 0;
}