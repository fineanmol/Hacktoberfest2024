#include <iostream>
using namespace std;

//Deep copy is needed when we need to copy pointers data

class Dummy
{
  private:
    int a,b;
    int *p;
  public:
    Dummy()
    {
      
      p=new int;
      
    }
    void setdata(int x,int y,int z)
     {
       a=x;
       b=y;
       *p=z;
       
      
       
     }
  
    void showdata()
    {
      cout<<"a= "<<a<<" "<<" b= "<<b<<" *p= "<<*p;
    }
  
   Dummy(Dummy &d)
   {
     a=d.a;
     b=d.b;   
      p=new int ;
       *p=*(d.p);
   }
  
  
};

int main()
{
   Dummy d1;
   d1.setdata(2,3,5);
   Dummy d2=d1;//cpy constructor called when initialized while declaration
   d2.showdata();
 
   
  
   
}
