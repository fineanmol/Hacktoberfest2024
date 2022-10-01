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

void doit()
{

    int n;
    int arr[2][n];
    fo1(i, 2)
    {
        fo1(i, n)
        {
            cin >> arr[2][n];
        }
    }
    bool flag = 0;
    int i = 0;
    if (arr[1][1] == 0 && arr[2][n] == 0)
    {
        fo1(j, n)
        {
            // if(i==1 && j==1){
            //     arr[]
            // }
            i++;
            j++;
            if (arr[i][j] != 0)
                flag = 1;

            i--;
        }
    }
    if (flag)
    {
        cout << "NO" << endl;
    }
    else
        cout << "YES" << endl;
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