#include<iostream>
using namespace std;
int findhcf(int num1,int num2)
{
    static int n = num2;
    if(num1%num2==0 && n%num2==0)
    return num2;
    else
    return findhcf(num1,num2-1);

}

int main()
{
    int num2,num1;
    
    cout<<"enter 2 nos.";
    cin>>num1>>num2;
    int maxi = max(num1,num2);
    int mini = min(num1,num2);
    int ans = findhcf(maxi,mini);
    cout<<ans;
}
