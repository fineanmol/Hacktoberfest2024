#include<iostream>
using namespace std;
int main(){
   int a =3;
   int *b =&a;
   // cout<<*b<<endl;
   // cout<<b<<endl;
   // cout<<&a;


// pointer to pointer
int **c =&b;
cout<<"the value of b is "<<&b<<endl;
cout<<"the value of b is "<<c<<endl;
cout<<"the value at address c is "<<*c<<endl;
cout<<"the value at address value at (value at  (c)) is "<<**c<<endl;

}