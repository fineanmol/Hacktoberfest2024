#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if ((a + b) % 3 != 0)
        {
            cout << "NO";
        }
        else
        {
            if (b > a * 2 || a > b * 2)
            {
                cout << "NO";
            }
            else
            {
                cout << "YES";
            }
        }
        cout << endl;
    }
    return 0;
}