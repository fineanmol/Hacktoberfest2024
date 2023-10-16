#include <bits/stdc++.h>
using namespace std;

int calculateEvenSum(int arr[], int N)
{
    unordered_map<int, int> frequencyMap;

    for (int i = 0; i < N; i++) {
        frequencyMap[arr[i]]++;
    }

    int sum = 0;

    for (auto itr = frequencyMap.begin(); itr != frequencyMap.end(); itr++) {
        if (itr->second % 2 == 0)
            sum += (itr->first) * (itr->second);
    }

    return sum;
}

int main()
{
    int arr[] = { 10, 20, 20, 40, 40 };
    int N = sizeof(arr) / sizeof(arr[0]);

    cout << calculateEvenSum(arr, N);

    return 0;
}
