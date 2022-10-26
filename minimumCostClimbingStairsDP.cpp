// Minimum cost of climbing strairs problem using dynamic programming
#include <bits/stdc++.h>
using namespace std;

int help(int step, int cost[])
{
    if (step >= (sizeof(cost) / sizeof(cost[0])))
        return 0;
    int total = cost[step]; // not working
    int op1 = help(step + 1, cost);
    int op2 = help(step + 2, cost);
    total += min(op1, op2);
    return total;
}

int main()
{

    int n;
    cin >> n;
    int cost[n];
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }

    int op0 = help(0, cost);
    int op1 = help(1, cost);

    cout << min(op0, op1) << endl;

    return 0;
}
