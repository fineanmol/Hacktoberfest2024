/*
====================================================================================
Title:  Sum of n natural Number Using Recursion
Author: Bhupendra Dangwal
====================================================================================
*/
#include<bits/stdc++.h>
using namespace std;

int sum(int num){
    if(num == 1){
        return 1;
    }
    return num+sum(num-1);
}
int main()
{
    int n = 10;
    int res = sum(n);
    cout<<"Sum: "<<res;

return 0;
}