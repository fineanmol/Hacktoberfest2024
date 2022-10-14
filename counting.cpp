#include <bits/stdc++.h>
using namespace std;
#define RANGE 255
#define ll long long int

vector<ll> countSort(vector<ll> arr)
{
    ll max = INT_MIN;
    for (auto i : arr)
    {
        if (i > max)
            max = i;
    }
    vector<ll> F(max + 1, 0);
    for (auto i : arr)
        F[i]++;
    // Commulative
    for (int i = 1; i <= arr.size(); i++)
    {
        F[i] = F[i] + F[i - 1];
    }
    vector<ll> ans(arr.size(), 0);
    for (int i = 0; i < arr.size(); i++)
    {
        F[arr[i]]--;
        ans[F[arr[i]]] = arr[i];
    }
    return ans;
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> V(n);
    for (auto &i : V)
        cin >> i;
    V = countSort(V);
    cout << endl;
    for (auto i : V)
        cout << i << "  ";
}
