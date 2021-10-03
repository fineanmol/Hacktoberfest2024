// find the nth term of fibonacci series using recursion
#include<iostream>
using namespace std;

int fibonacci(int n){
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    int ans = fibonacci(n-1)+fibonacci(n-2);
    return ans;
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    cout<<fibonacci(n)<<endl;
    return 0;
}
