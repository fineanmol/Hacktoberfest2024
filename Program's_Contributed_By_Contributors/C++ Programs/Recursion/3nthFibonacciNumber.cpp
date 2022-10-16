/*
====================================================================================
Title:  Nth Fibonacci Number using recursion
Author: Bhupendra Dangwal
====================================================================================
*/
#include<bits/stdc++.h>
using namespace std;

int fibo(int num){
    //  0th term of fibonacci series is 0
    if(num == 0){
        return 0;
    }

    //  1st and 2nd term of fibonacci series is 1
    if(num == 1 || num == 2){
        return 1;
    }

    int count = 0;

    return fibo(num-1)+fibo(num-2);
}

int main()
{
    int n = 80;
    int res = fibo(n);
    cout<<"Nth term: "<<res;    
    return 0;
}