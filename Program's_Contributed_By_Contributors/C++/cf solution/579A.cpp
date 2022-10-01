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
    lli x, count = 0;
    cin >> x;
    int g;
    while (x != 0)
    {

        g = x % 2;
        if (g == 1)
        {
            count++;
        }
        x = x / 2;
    }
    cout << count << endl;
}
