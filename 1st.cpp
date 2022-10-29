#include<iostream>
using namespace std;
 
int main()
{
    int a,b,c,d,e;
    cout<<"Enter the marks obtained in 1st subject. \n";
    cin>>a;

    cout<<"Enter the marks obtained in 2nd subject. \n";
    cin>>b;

    cout<<"Enter the marks obtained in 3rd subject. \n";
    cin>>c;

    cout<<"Enter the marks obtained in 4th subject. \n";
    cin>>d;

    cout<<"Enter the marks obtained in 5th subject. \n";
    cin>>e;

    float per=(a+b+c+d+e)*100/500;
    cout<<"The total percentage of the student is:"<<per;

    return 0;
}