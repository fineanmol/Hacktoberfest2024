#include<bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size()-1;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else if(nums[mid]==2)
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
    int main()
    {
    vector<int> nums = {1,2,0,2,0,1,1,2,0};
    sortColors(nums);
    for(auto x: nums)
    	cout<<x<<" ";
    cout<<endl;
    }
   
