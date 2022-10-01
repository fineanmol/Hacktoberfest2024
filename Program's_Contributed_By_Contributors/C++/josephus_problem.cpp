// Problem-link-1 : https://practice.geeksforgeeks.org/problems/josephus-problem/1
// problem-link-2 : https://practice.geeksforgeeks.org/problems/game-of-death-in-a-circle1840/1

#include <bits/stdc++.h>
using namespace std;

int josephus(int n, int k)
{
    if(n==1) return 1;
    return (josephus(n-1,k) + (k-1)) % (n+1);
}

int main()
{
    int n,k;
    cin>>n>>k;
    
    cout<<josephus(n,k)<<endl;

    return 0;
}
