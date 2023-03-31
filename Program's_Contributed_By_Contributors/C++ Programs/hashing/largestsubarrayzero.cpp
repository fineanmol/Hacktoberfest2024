#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> nums={1,-1,3,2,-2,-8,1,7,2,6,10};
	map<int,int> mp;
	int sum = 0;
	int len = 0;
	for(int i=0;i<nums.size();i++)
	{
		sum+=nums[i];
		if(mp.find(sum)!=mp.end())
		{
			len = max(len, i-mp[sum]);
		}
		else
			mp[sum]=i;
	}
	cout<<len<<endl;
	return 0;
}