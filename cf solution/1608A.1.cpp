#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define fo1(x, y) for (lli x = 0; x < y; x++)
#define fo2(x, y) for (lli x = 1; x <= y; x++)

const ll n = 10000000;
bitset<10000005> b;
vector<ll> primes;

void sieve()
{
    b.set();
    b[0] = b[1] = 0;
    for (ll i = 2; i <= n; i++)
    {
        if (b[i])
        {
            primes.push_back(i);
            for (ll j = i * i; j <= n; j = j + i)
                b[j] = 0;
        }
    }
}
int main()
{
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        for (int i = 0; i < n; i++)
            cout << primes[i] << " ";
        cout << endl;
    }
}