/*
====================================================================================
Title:  Nth Power Of Number Using Recursion
Author: Bhupendra Dangwal
====================================================================================
*/
#include<bits/stdc++.h>
using namespace std;

int NthPower(int num, int pow){
    if(pow == 0){
        return 1;
    }

    return num*NthPower(num, pow-1);
}
int main()
{
    int number = 5;
    int power = 3;

    int res = NthPower(number, power);
    cout<<"NthPower: "<<res;
    return 0;
}