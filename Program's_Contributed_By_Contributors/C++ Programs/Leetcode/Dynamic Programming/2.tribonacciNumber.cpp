#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        int tribonacciArray[n+3];
        tribonacciArray[0]=0;        
        tribonacciArray[1]=1;
        tribonacciArray[2]=1;

        for (int i=3;i<=n;i++){
            tribonacciArray[i] = tribonacciArray[i-1] + tribonacciArray[i-2] + tribonacciArray[i-3];
        }
        return tribonacciArray[n];
    }
};