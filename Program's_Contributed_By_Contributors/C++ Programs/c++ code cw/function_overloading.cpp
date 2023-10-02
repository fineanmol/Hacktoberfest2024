#include<iostream>
using namespace std;
int sum (int a , int b){
    cout<<"using function with 2 argumennts "<<endl;
    return a+b;
}
int sum(int a, int b, int c){
    cout<<"using function with 3 argumennts "<<endl;
    return a+b+c;
}
// calculate the volume of a cylinder
int volume(double r, int h){
    return(3.14 * r * r *h);
}
// calculate the volume of a cube
int volume(int a){
    return(a*a*a);
}
int volume(int l , int b, int h){
    return(l*b*h);
}
int main(){
int a =5;
int h =6;
int r =8;
int l =4;
int b =8;
    cout<<"The sum of 3 and 6 is "<<sum(3,6)<<endl;
    cout<<"The sum of 3 and 6 is "<<sum(3,6,7)<<endl;
    cout<<"the volume of cube is "<<volume(a)<<endl;
    cout<<"the volume of cube is "<<volume(r,h)<<endl;
    cout<<"the volume of cube is "<<volume(l,b,h)<<endl;

    return 0;

}