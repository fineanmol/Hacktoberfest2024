#include <iostream>
using namespace std;

//type conversion
//primitive to class can be implememted using constructors

class Complex
{
  
  
  private:
    int a,b;
  
  public:
    
  Complex(){  }//run for Complex c1;
  
  Complex(int k)//run for c1=x;
  {
   a=k;
  }
  
  void setdata(int x, int y)
  {
    
     a=x;
     b=y;
    
  }
  
  void showdata()
  {
    
    cout<<"a="<<a<<"b="<<b;
    
  }
  
};




int main()
{
 Complex c1;//default const. will run for this.
 int x=5;
 c1=x;
 c1.showdata();
}
