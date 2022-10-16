/*
====================================================================================
Title:  Factorial of number using recursion
Author: Bhupendra Dangwal
====================================================================================
*/
#include<bits/stdc++.h>
using namespace std;

int factorial(int num){
    if(num == 0){
        return 1;
    }
    return num*(factorial(num-1));
}

int main()
{
    int n = 6;

    long int fact = factorial(n);
    cout<<fact;

return 0;
}