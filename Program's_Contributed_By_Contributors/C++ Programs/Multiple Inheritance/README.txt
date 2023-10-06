WHAT IS MULTIPLE INHERITANCE

Multiple Inheritance is the concept of the Inheritance in C++ that allows a child class to inherit properties or behaviour from multiple base classes. Therefore, we can say it is the process that enables a derived class to acquire member functions, properties, characteristics from more than one base class.

Syntax of the Multiple Inheritance
class A  
{  
// code of class A  
}  
class B  
{  
// code of class B  
}  
class C: public A, public B (access modifier class_name)  
{  
// code of the derived class  
}  
In the above syntax, class A and class B are two base classes, and class C is the child class that inherits some features of the parent classes.