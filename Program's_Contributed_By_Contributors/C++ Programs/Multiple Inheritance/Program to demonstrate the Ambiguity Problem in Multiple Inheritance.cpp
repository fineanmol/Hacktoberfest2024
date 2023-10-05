#include <iostream>  
#include <conio.h>  
  
using namespace std;  
  
// create class A  
class A  
{  
    public:   
    void show()  
    {  
        cout << " It is the member function of class A " << endl;  
    }  
 };   
   
 // create class B  
 class B  
{  
    public:   
    void show()  
    {  
        cout << " It is the member function of class B " << endl;  
    }  
 };  
   
   
 // create a child class to inherit the member function of class A and class B  
 class child: public A, public B  
 {  
    public:  
        void disp()  
        {  
            cout << " It is the member function of the child class " << endl;  
         }  
 };  
   
 int main ()  
 {  
    // create an object of the child class to access the member function  
    child ch;  
    ch.show(); // It causes ambiguity   
    ch.disp();  
    return 0;  
 }   