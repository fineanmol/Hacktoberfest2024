#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> nums= {-2,1,4,-3,2,-5,-1,6,-4,3,5};
	int local_sum=0,global_sum=0;
	for(int i=0;i<nums.size();i++)
	{
		cout<<nums[i]<<"  ";
		local_sum = max(local_sum+nums[i],nums[i]);
		global_sum = max(local_sum,global_sum);
	}
	cout<<endl;
	cout<<global_sum<<endl;
	return 0;
}