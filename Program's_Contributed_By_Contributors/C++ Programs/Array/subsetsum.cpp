// because of the complexity of the size of the array or list we are going to make the tc as 2^n
// so to avoid it we will use dp

#include <bits/stdc++.h>
using namespace std;
bool SubsetSum(int arr[], int n, int sum)
{
    bool subset[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        subset[i][0] = true;
    }

    for (int i = 1; i <= sum; i++)
    {
        subset[0][i] = false;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < arr[i - 1])
            {
                subset[i][j] = subset[i - 1][j];
            }
            if (j >= arr[i - 1])
            {
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - arr[i - 1]];
            }
        }
    }
    
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
            printf("%4d", subset[i][j]);
        cout << "\n";
    }

    return subset[n][sum];
}
int main()
{
    int n;
    cin >> n;
    int sum;
    cin >> sum;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (SubsetSum(arr, n, sum) == true)
    {
        cout << "Found a subset :";
    }
    else
    {
        cout << "No subset found :";
    }
}
