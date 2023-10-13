#include<bits/stdc++.h>
using namespace std;

int main() {
    cout << "Enter the number of denominations: ";
    int n;
    cin >> n;

    int denomination[n];
    cout << "Enter the denominations in ascending order: ";
    for (int i = 0; i < n; i++) {
        cin >> denomination[i];
    }

    int V;
    cout << "Enter the amount for which you want to find the minimal number of denominations: ";
    cin >> V;

    sort(denomination, denomination + n);
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) {
        while (V >= denomination[i]) {
            V -= denomination[i];
            ans.push_back(denomination[i]);
        }
    }
    cout << "Following is minimal number of change for " << V << ": ";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}
