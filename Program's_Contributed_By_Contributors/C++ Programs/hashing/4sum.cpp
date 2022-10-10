#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> nums = {4,4,1,2,3,4,2,3,2,1,1};
	int target = 9;
	vector<vector<int>>ans;
	if(nums.size()<4)
		return 0;
	int n = nums.size();
	sort(nums.begin(), nums.end());

	for(int i=0;i<n;i++)
	{
		if(i>0 and nums[i]==nums[i-1])
			continue;
		for(int j=i+1;j<n;j++)
		{
			if(j>i+1 and nums[j]==nums[j-1])
				continue;
			int l = j+1;
			int r = n-1;
			int x = target - nums[i] - nums[j];

			while(l<r)
			{
				if(l>j+1 and nums[l]==nums[l-1])
				{
					l++;
					continue;
				}
				if(r<n-1 and nums[r]==nums[r+1])
				{
					r--;
					continue;
				}
				if(nums[l]+nums[r]==x)
				{
					vector<int> temp;
					temp.push_back(nums[i]);
					temp.push_back(nums[j]);
					temp.push_back(nums[l]);
					temp.push_back(nums[r]);
					cout<<nums[i]<<" "<<nums[j]<<" "<<nums[l]<<" "<<nums[r]<<endl;
					ans.push_back(temp);
					l++;
					r--;
				}
				if(nums[l]+nums[r]>x)
				{
					r--;
				}
				else if(nums[l]+nums[r]<x)
				{
					l++;
				}
			}
		}
	}
	return 0;
}