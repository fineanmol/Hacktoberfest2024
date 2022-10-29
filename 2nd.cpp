#include<iostream>
using namespace std;

int main()
{
    int l,b;
    cout<<"Enter the length of rectangle in centimeters. \n";
    cin>>l;

    cout<<"Enter the breadth of rectangle in centimeters. \n";
    cin>>b;

    int r;
    cout<<"Enter the length of radius in centimeters. \n";
    cin>>r;

    int p=(l+b)*2;
    float cir =r*r*22/7;

    cout<<"The perimeter of the rectangle in centimeters is: "<<p<<endl;
    cout<<"The area of the circle in centimeters is:"<<cir<<endl;

    return 0;
}