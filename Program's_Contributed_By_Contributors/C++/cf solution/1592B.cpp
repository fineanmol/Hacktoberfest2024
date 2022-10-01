#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
#define fo1(x, y) for (lli x = 0; x < y; x++)
#define fo2(x, y) for (lli x = 1; x <= y; x++)
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
// unordered_map<lli, lli> mp;
// lli dp[100005] = {0};
#define MAX 1000000007
//lli g[6][6];
// map<lli, vector<int>> mp;
// lli arr[1000000];

void doit1()
{
    bool flag = 1;
    int n, x, s = 0, j;
    cin >> n >> x;
    int arr[n];
    arr[0] = 0;
    j = 0;
    fo2(i, n)
    {
        cin >> arr[i];
        if (arr[j] > arr[i])
        {
            flag = 0;
        }
        j++;
    }
    sort(arr, arr + n);

    if (flag)
    {
        cout << "YES" << endl;
    }
    else if (arr[n] - arr[1] < x)
        cout << "NO" << endl;
    else
    {

        int N = n;
        int M = 1;
        fo2(i, n)
        {
            if (abs(arr[N] - arr[M]) > x)
            {
                N--;
                s++;
            }
            else if (abs(arr[N] - arr[M]) < x)
                M++;
            else if (abs(arr[N] - arr[M]) == x)
            {
                s++;
            }
        }
        if (s >= (n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

void doit()
{
    bool flag = 1;
    int n, x, s = 0, j, k = 1;
    cin >> n >> x;
    int arr[n], b[n];

    fo1(i, n)
    {
        cin >> arr[i];
        b[i] = arr[i];
    }
    sort(b, b + n);
    for (int i = n - x; i < x; i++)
    {
        flag &= (arr[i] == b[i]);
    }
    cout << ((flag) ? "YES" : "NO") << endl;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    w(t)
    {
        doit();
    }
}