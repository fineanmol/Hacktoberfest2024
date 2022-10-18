#include<bits/stdc++.h>
using namespace std;

int merge(vector<int>& nums, vector<int>& temp, int low, int mid, int high)
{
	int i,j,k;
	int count = 0;
	i = low;
	j = mid;
	k = low;
	while(i<=mid-1 and j<=high)
	{
		if(nums[i]<=nums[j])
		{
			temp[k++] = nums[i++];
		}
		else
		{
			temp[k++] = nums[j++];
			count+= mid-i;
		}

	}
	while(i<mid)
	{
		temp[k++]=nums[i++];
	}
	while(j<=high)
	{
		temp[k++] = nums[j++];
	}
	for(int i=low;i<=high;i++)
		nums[i]=temp[i];
	return count;
}

int mergesort(vector<int>& nums, vector<int>& temp, int low, int high)
{
	int mid, count=0;
	
	if(high>low)
	{
		mid = (low+high)/2;
		count+=mergesort(nums, temp, low, mid);
		count+=mergesort(nums, temp, mid+1, high);
		count+=merge(nums, temp, low, mid+1, high);
	}
	return count;
}
int main()
{
	vector<int> nums = {5,2,3,4,1};
	vector<int> temp(nums.size());
	int ans = mergesort(nums, temp, 0, nums.size()-1);
	cout<<ans<<endl;
	return 0;
}