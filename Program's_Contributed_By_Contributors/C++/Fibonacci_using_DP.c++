#include<bits/stdc++.h>

using namespace std;

int fib(int n){
    int prev = 0, cur = 1, c, i;
    if(n == 0)  return prev;
    if(n == 1)  return cur;
    
    for(i = 2; i <= n; i++){
       c = prev + cur;
       prev = cur;
       cur = c;
    }
    return cur;
}

int main(){
    int n;  cin>>n;
    int res = fib(n);
    cout<<"N-th Fibonacci Number: "<<res<<endl;
    return 0;
}

// Time Complexity: O(n) 
// Extra Space: O(1)