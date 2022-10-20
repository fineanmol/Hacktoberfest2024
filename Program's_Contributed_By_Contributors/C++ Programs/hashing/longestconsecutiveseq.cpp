#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> nums = {2,4,100,3,102,101,1};
	set<int> st;
	for(auto x:nums)
		st.insert(x);
	int len = 0;
	for(int i=0;i<nums.size();i++)
	{
		if(st.count(nums[i]-1))
			continue;
		int curr = 1;
		int val = nums[i];
		while(st.count(val+1))
		{
			curr++;
			val++;
		}
		len = max(len,curr);
	}
	cout<<len<<endl;
	return 0;

}