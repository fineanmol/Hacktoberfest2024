#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    vector<int> temp(nums.size());
    int n = nums.size();
    for (int i = 0; i < nums.size(); i++)
    {
        temp[(i + k) % n] = nums[i];
    }
    nums = temp;
}

int main()
{
    vector<int> nums = {7, 1, 5, 3, 6, 4};
    int k = 3;
    cout << "Original array: ";
    for (auto x : nums)
    {
        cout << x << " ";
    }
    cout << endl;
    rotate(nums, k);
    cout << "Rotated array: ";
    for (auto x : nums)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}