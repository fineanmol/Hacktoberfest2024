#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>nums = {2,7,11,15,6,8,10};
    sort(nums.begin(), nums.end());
    int target = 9;
    for (int i = 0; i < nums.size(); i++) 
    {
            for (int j = i + 1; j < nums.size(); j++) 
            {
                if (nums[i] + nums[j] == target) 
                {
                    cout<<"2Sum found : "<<nums[i]<<" and "<<nums[j] << " = " << target<<endl;
                    return 0;
                }
            }
        }
    cout<<"2Sum not found"<<endl;
    return 0;
}
