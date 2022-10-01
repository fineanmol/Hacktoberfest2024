#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
// unordered_map<lli, lli> mp;
// lli dp[100005] = {0};

// auto sgn(int x)
// {
//     if (x > 0)
//         return 1;
//     else
//         return -1;
// };
int main()
{

    // string s, *p;
    char s[100005], *p;
    cin >> s;
    if ((p = strstr(s, "AB")) && strstr(p + 2, "BA"))
        cout << "YES" << endl;
    else if ((p = strstr(s, "BA")) && strstr(p + 2, "AB"))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
