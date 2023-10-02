#include<iostream>
using namespace std;

// functions prototype 
// Type , functions name , arguments
int sum(int a , int b){
    int c = a+b;
    return c;
}
int subtract(int a , int b){
    int c = a-b;
    return c;
}
int multi(int a , int b){
    int c = a*b;
    return c;
}
int divide(int a , int b){
    int c = a/b;
    return c;
}
 int main(){
int num1,num2;
cout<<"enter a value "<<endl;
cin>>num1;
cout<<"enter a value "<<endl;
cin>>num2;
cout<<"sum "<<sum(num1,num2)<<endl;
cout<<"substract "<<subtract(num1,num2)<<endl;
cout<<"multiply "<<multi(num1,num2)<<endl;
cout<<"divide "<<divide(num1,num2)<<endl;
return 0;
}