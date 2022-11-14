//it is called automatically
/*
destruction follows a order
last to be created is destroyed first


OUTPUT:

zero args constructor
parameterized args constructor
copy constructor
 destroyed //due to  end of scope of s3
copy constructor //k created
Helloo //controll goes to friend func
 destroyed
 destroyed
 destroyed
*/
#include<iostream>
using namespace std;
class student{
    int roll;
    public:
    student(){cout<<"zero args constructor"<<endl;}
    student(int k){cout<<"parameterized args constructor"<<endl;}
    student(student &k){;cout<<"copy constructor"<<endl;}
    ~student(){cout<<" destroyed"<<endl;}//destructor
    friend void show(student k){cout<<"Helloo"<<endl;}//student k will be created with an argument

};
int main(){
    student s1;
    student s2(5);
    {
        student s3(s2);//properties of s2 gets copied in k and is newly created due to pass by value
    }
    // s3.show()//not allowed as not declared in this scope
    show(s2);
    return 0;
}