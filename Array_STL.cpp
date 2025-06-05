#include <iostream>
using namespace std;

template <class X> class ArrayList
{
 private:
   
 struct Control
 {
   int endlim;
   X *arr;
 };
 
 
 Control *s;
 
 public:
 
 ArrayList(int endlim)//local var
 {
   s=new Control;
   s->endlim=endlim;
   s->arr=new X[s->endlim];
 }
 
 void setvalue(int index, X data)
 {
   if(index>=0 && index<=s->endlim-1)
   {
     s->arr[index]=data;
   }
   else
   {
     cout<<"wrong index \n";
   }
 }
 
 void showvalue(int index,X &data)
 {
   
   
    if(index>=0 && index<=s->endlim-1)
   {
    data= s->arr[index];
    cout<<"\nvalue @ index = "<<index<<" is = "<<data;
   }
   else
   {
     cout<<"wrong index \n";
   }
   
 }
 void viewall()
 {
   int i;
   for(i=0;i<s->endlim;i++)
   {
     cout<<"\nVALUE AT "<<i<<"=="<<s->arr[i];
   }
   
 }
  
};

int main()
{
  ArrayList <int> obj1(4); //here we have to mention datatype of inputs
  obj1.setvalue(0,21);
  obj1.setvalue(1,22);
  obj1.setvalue(2,23);
  obj1.setvalue(3,24);
   

  //obj1.showvalue(0,data);
  obj1.viewall();
  
    
}
