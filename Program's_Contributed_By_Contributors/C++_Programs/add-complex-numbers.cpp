/* C++ Program to add two Complex Numbers */
#include<iostream>
using namespace std;
class Complex{
public:
    int real;
    int imag;
     /* Function to set the values of
      * real and imaginary part of each complex number
      */
     void setvalue()
    {
        cin>>real;
        cin>>imag;
    }
	/* Function to display the sum of two complex numbers */
    void display()
    {
        cout<<real<<"+"<<imag<<"i"<<endl;
    }
	/* Function to add two complex numbers */
 
    void sum(Complex c1, Complex c2)
    {
        real=c1.real+c2.real;
        imag=c1.imag+c2.imag;
    }
    };
int main()
    {
        Complex c1,c2,c3;
        cout<<"Enter real and imaginary part of first complex number"<<endl;
        c1.setvalue();
        cout<<"Enter real and imaginary part of second complex number"<<endl;
        c2.setvalue();
        cout<<"Sum of two complex numbers is"<<endl;
        c3.sum(c1,c2);
        c3.display();
    return 0;
    }
