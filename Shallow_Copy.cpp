#include <iostream>
using namespace std;

//Shallow copy

class Dummy
{
  private:
    int a,b;
  public:
    
    void setdata(int x,int y)
     {
       a=x;
       b=y;
       
     }
  
    void showdata()
    {
      cout<<"a= "<<a<<" "<<"b= "<<b<<"\n";
    }
  
  
  
  
};

int main()
{
   Dummy d1;
   d1.setdata(2,3);
   Dummy d2=d1;//cpy constructor called when initialized while declaration
   d2.showdata();
 
   d1.setdata(4,5);
   Dummy d3;
   
   d3=d1;//implicit copy assignment operator
   
   d3.showdata();
  //2 types of shallow copy
   
}
