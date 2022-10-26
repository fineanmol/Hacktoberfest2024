#include<bits/stdc++.h>
using namespace std;


int merge(vector<int>& nums, int low, int mid, int high)
{
	int count = 0;
	int j = mid + 1;
	for(int i=low;i<=mid;i++)
	{
		while(j<=high and nums[i]> 2*nums[j])
		{
			j++;
		}
		count+=(j-(mid+1));
	}
	vector<int> temp;
	int i = low;
	int k = mid+1;
	while(i<=mid and k<=high)
	{
			if(nums[i]<=nums[k])
				temp.push_back(nums[i++]);
			else
				temp.push_back(nums[k++]);
	}
	while(i<=mid)
		temp.push_back(nums[i++]);
	while(k<=high)
		temp.push_back(nums[k++]);
	for(int i=low;i<=high;i++)
		nums[i]=temp[i-low];
	return count;
}

int mergesort(vector<int>& nums, int low, int high)
{
	if(low>=high)
		return 0;
	int mid = (low+high)/2;
	int count = 0;
	count+=mergesort(nums,low,mid);
	count+=mergesort(nums,mid+1,high);
	count+=merge(nums,low,mid,high);
	return count;
}
int main()
{
	vector<int> nums = {40,25,19,12,9,6,2};
	cout<<mergesort(nums,0,nums.size()-1)<<endl;
	return 0;
}