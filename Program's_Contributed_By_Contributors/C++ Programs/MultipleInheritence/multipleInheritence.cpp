
// Multiple Inheritance is a feature of C++ where a class can inherit from more than one classes.
// The constructors of inherited classes are called in the same order in which they are inherited.
//For example, in the following program, B’s constructor is called before A’s constructor.
// A class can be derived from more than one base class.

// Eg: 

// (i) A CHILD class is derived from FATHER and MOTHER class
// (ii) A PETROL class is derived from LIQUID and FUEL class.

//Syntax:

// class A
// { 
// ... .. ... 
// };
// class B
// {
// ... .. ...
// };
// class C: public A,public B
// {
// ... ... ...
// };



//Sample explanation with code

#include<iostream>
using namespace std;

class A
{
public:
A() { cout << "A's constructor called" << endl; }
};

class B
{
public:
B() { cout << "B's constructor called" << endl; }
};

class C: public B, public A // Note the order
{
public:
C() { cout << "C's constructor called" << endl; }
};

int main()
{
	C c;
	return 0;
}
//Output-->
// B's constructor called
// A's constructor called
// C's constructor called