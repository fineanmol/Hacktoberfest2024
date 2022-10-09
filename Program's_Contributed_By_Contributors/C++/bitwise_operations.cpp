#include <bits/stdc++.h>
using namespace std;

int getithbit(int n, int i)
{
    int mask = (1 << i);
    return (n & mask) > 0 ? 1 : 0;
}

void setithbit(int &n, int i)
{
    int mask = (1 << i);

    n = (n | mask);
}

void clearithbit(int &n, int i)
{
    int mask = ~(1 << i);

    n = (n & mask);
}

void updateithbit(int &n, int i, int v)
{
    clearithbit(n, i);
    int mask = (v << i);
    n = n | mask;
}

void clearlastbits(int &n, int i)
{
    int mask = (-1 << i);
    n = n & mask;
}

void clearbitsinrange(int &n, int i, int j)
{
    int a = (-1 << (j + 1));
    int b = (1 << i) - 1;
    int mask = a | b;

    n = n & mask;
}

int main()
{
    int n = 31;
    int i = 1, j = 3;
    // cin >> i;

    // cout << getithbit(n,i);

    //    setithbit(n,i);
    //     cout << n;

    // clearithbit(n, i);
    // cout << n;

    // updateithbit(n,i,1);
    // clearlastbits(n,2);
    clearbitsinrange(n, i, j);
    cout << n;
}
