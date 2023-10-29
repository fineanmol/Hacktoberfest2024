#include <iostream>
using namespace std;

int main()
{
    float pm,cm,diff,net,j;
    cout << "Enter last month unit consumption: ";
    cin >> pm;
    cout << "Enter current month unit consumption: ";
    cin >>cm;
    diff=cm-pm;
    if (diff>0)
    {
        if(diff<=100)
        {
            j=diff*2;
        }
        else if(diff>100 && diff<=200)
        {
            j=diff-100;
            j=j*3;
            net=j+200;
        }
        else if(diff>200 && diff<=300)
        {
            j=diff-200;
            j=j*4;
            net=j+500;
        }
        else
        {
            j=diff-300;
            j=j*5;
            net=j+900;
        }
        net=net+100;
        cout << "Net unit consumption: " << diff << "\nTotal Bill: ₹" << net;
    }
    else
    {
        cout << "Invalid Input!";
    }
    return 0;
}