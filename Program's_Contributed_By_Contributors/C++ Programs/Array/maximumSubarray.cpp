#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int msf = INT_MIN;
        int max = 0;
        for (int i = 0; i < n; i++)
        {
            max = max + nums[i];
            if (msf < max)
            {
                msf = max;
            }
            if (max < 0)
            {
                max = 0;
            }
        }
        return msf;
    }
};

int main()
{
    // Input: Enter the number of elements in the array
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Input: Enter the elements of the array
    vector<int> nums(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution solution;
    int maxSum = solution.maxSubArray(nums);

    // Output: Display the maximum subarray sum
    cout << "Maximum subarray sum: " << maxSum << endl;

    return 0;
}
