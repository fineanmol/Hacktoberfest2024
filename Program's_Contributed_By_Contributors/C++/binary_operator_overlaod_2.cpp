#include<iostream>
#include<conio.h>
using namespace std;
class complex
{
  int a,b;
  public:
  friend istream& operator >>(istream &,complex&);
  friend ostream& operator <<(ostream &,complex);
};
istream& operator >>(istream &input,complex &c)
{
 input>>c.a>>c.b;
 return input;
}
ostream& operator <<(ostream &output,complex c)
{
 output<<"a="<<c.a<<"  b="<<c.b;
 return output;
}
int main()
{
 complex c1;
 cout<<"Enter Complex Number:"<<endl;
 cin>>c1;   //operator >>(cin,c1);
 cout<<"You Entered :"<<endl;
 cout<<c1;  //operator <<(cout,c1);
 getch();
}
