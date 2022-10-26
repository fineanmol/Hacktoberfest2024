//contributed by: Allen-Saji

#include <bits/stdc++.h>
using namespace std;

int sum_of_n(int n)
{
    // base case
    if (n == 1)
        return 1;

    // recursive case
    int sum = sum_of_n(n - 1) + n;

    return sum;
}

int main()
{
    int n;
    cin >> n;

    cout << sum_of_n(n) << endl;
}
