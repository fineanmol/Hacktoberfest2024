#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        int fibArray[n+2];        
        fibArray[0]=0;
        fibArray[1]=1;
        for (int i=2;i<=n;i++){
            fibArray[i] = fibArray[i-1] + fibArray[i-2];          
        }
        return fibArray[n];
    }
};