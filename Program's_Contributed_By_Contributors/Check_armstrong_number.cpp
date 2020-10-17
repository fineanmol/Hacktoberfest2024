#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n,temp,remainder,x=0,ans=0;
    cout<<"Enter a number:"<<endl;
    cin>>n;
    temp=n;
    while(temp!=0){
        temp=temp/10;
        x++;
    }
    temp=n;
    while(temp!=0)
    {
        remainder=temp%10;
        int power=round(pow(remainder,x));
        ans+=power;
        temp=temp/10;
    }
    if(ans==n)
        cout<<"Armstrong number";
    else
        cout<<"Not an armstrong number";
    return 0;
}
