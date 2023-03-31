#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> nums = {1,1,1,2,3,4,4,4,4,5};
	int i = 0, j = 1;
	while(j<nums.size())
	{
		if(nums[i]==nums[j])
			j++;
		else
		{
			i++;
			nums[i] = nums[j];
		}
	}
	for(int k = 0;k<=i;k++)
		cout<<nums[k]<<" ";
	cout<<endl;
	return 0;
}