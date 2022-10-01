#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define fo1(x, y) for (ll x = 0; x < y; x++)
#define fo2(x, y) for (ll x = 1; x <= y; x++)
const int N = 2e5 + 10;
int a[N];

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll arr[7];
        fo1(i, 7)
        {
            cin >> arr[i];
        }
        ll y;
        cout << arr[0] << " " << arr[1] << " ";
        ll x = arr[0] + arr[1];
        cout << arr[6] - x << endl;
    }
}

// int arr[7];
// fo1(i, 7)
// {
//     cin >> arr[i];
// }

// cout << arr[0] << " " << arr[1] << " ";
// int x = arr[0] + arr[1];
// for (int i = 2; i < 7; i++)
// {
//     if (x != arr[i])
//     {
//         cout << arr[i];
//         break;
//     }
// }