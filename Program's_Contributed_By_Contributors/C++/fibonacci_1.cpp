#include <iostream>
using namespace std;
#define ll long long
ll n;

ll fibonacci(ll i)
{
    if (i <= 2)
    {
        return 1;
    }
    return fibonacci(i - 1) + fibonacci(i - 2);
}

int main()
{
    cin >> n;
    cout << fibonacci(n);
}
