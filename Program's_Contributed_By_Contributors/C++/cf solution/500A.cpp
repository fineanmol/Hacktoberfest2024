#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
//#define for(i,a) for(int i=1;i<=(a);i++)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout.precision(22);
    lli n, t;
    cin >> n >> t;
    lli arr[n];
    for (lli i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    lli i = 1;
    bool flag = 0;
    while (i <= n)
    {
        if (i == t)
        {
            flag = 1;
            break;
        }
        if (i > t)
        {
            break;
        }
        i += arr[i - 1];
    }

    if (flag == 1)
        cout << "YES";
    else
        cout << "NO";
}
