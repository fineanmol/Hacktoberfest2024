#include<bits/stdc++.h>
using namespace std;

int main() {
    cout << "Enter the number of denominations: ";
    int numberOfCoins;
    cin >> numberOfCoins;

    int denomination[numberOfCoins];
    cout << "Enter the denominations in ascending order: ";
    for (int i = 0; i < numberOfCoins; i++) {
        cin >> denomination[i];
    }

    int totalAmount;
    cout << "Enter the amount for which you want to find the minimal number of denominations: ";
    cin >> totalAmount;

    sort(denomination, denomination + numberOfCoins);
    
    vector<int> ans;
    int x = totalAmount;
    for (int i = numberOfCoins - 1; i >= 0; i--) {
        while (x >= denomination[i]) {
            x -= denomination[i];
            ans.push_back(denomination[i]);
        }
    }
    cout << "Following is minimal number of change for " << totalAmount << ": ";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}
