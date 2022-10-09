#include<iostream>
#include<conio.h>

using namespace std;

class complex
{
 int a,b;
 public:
   void getdata(int x,int y)
    { a=x, b=y; }
   void showdata()
   {
    cout<<"a="<<a;
    cout<<" b="<<b<<endl;
   }
   complex operator +(complex c);
  // friend complex operator +(complex,complex);
};
 complex complex:: operator +(complex c)
 {
  complex temp;
  temp.a=a+c.a;
  temp.b=b+c.b;
  return temp;
 }
/* complex operator +(complex x,complex y)   //FRIEND FUNCTION
   {
    complex temp;
    temp.a=x.a+y.a;
    temp.b=x.b+y.b;
    return temp;
   }
*/

int main()
{
 complex c1,c2,c3;
 c1.getdata(5,6);
 c2.getdata(4,5);
 c3=c1.operator+(c2);//    c3=c1+c2;
 c3.showdata();
 getch();
}
