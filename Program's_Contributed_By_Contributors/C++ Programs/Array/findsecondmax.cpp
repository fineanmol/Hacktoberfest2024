#include bits/stdc++.h

using namespace std;

int main()
{
    vector<int> arr;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());

    cout << arr[n - 3];

}