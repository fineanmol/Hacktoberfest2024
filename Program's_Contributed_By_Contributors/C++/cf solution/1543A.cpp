#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
#define fo1(x, y) for (lli x = 0; x < y; x++)
#define fo2(x, y) for (lli x = 1; x <= y; x++)
// unordered_map<lli, lli> mp;
// lli dp[100005] = {0};
#define MAX 1000000007
//lli dp[MAX];
//lli arr[10000];
lli a, b, a1, a2, b1, b2;

int gcd(lli x, lli y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    lli t;
    cin >> t;
    while (t--)
    {

        lli ans, ans1;
        cin >> a >> b;
        a1 = a;
        a2 = a;
        b1 = b;
        b2 = b;
        ans = abs(a - b);
        lli count = 0, count1 = 0;
        lli p = 0;
        lli x = 0;
        fo1(i, ans)
        {

            a1 = a1 - 1;
            b1 = b1 - 1;
            a2 = a2 + 1;
            b2 = b2 + 1;
            ans1 = max(gcd(a1, b1), max(gcd(a, b), gcd(a2, b2)));
            count++;
            if (ans1 > p)
                count1 = count;
            p = max(p, ans1);
        }

        if (a == b)
        {
            cout << 0 << " " << 0;
        }
        else if (abs(a - b) == 1)
            cout << 1 << " " << 0;

        else
            cout << p << " " << count1;
        cout << endl;
    }
}
