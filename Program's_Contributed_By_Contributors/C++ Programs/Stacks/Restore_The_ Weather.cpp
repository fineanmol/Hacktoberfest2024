#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k, x;
        cin >> n >> k;

        vector<int> input1(n, 0);
        vector<pair<int, int>> pq;

        for (int i = 0; i < n; i++)
        {
            cin >> x;
            pq.push_back({x, i});
        }
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            input1[i] = x;
        }

        sort(pq.begin(), pq.end());
        sort(input1.begin(), input1.end());

        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++)
        {
            ans[pq[i].second] = input1[i];
        }
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}