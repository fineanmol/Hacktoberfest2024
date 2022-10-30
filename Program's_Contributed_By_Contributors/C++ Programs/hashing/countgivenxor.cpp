#include<bits/stdc++.h>
using namespace std;

int main()
{

	vector<int> nums = {4,2,2,6,4};
	int target = 6;
	map<int,int> mp;
	int count = 0;
	int xorr = 0;
	for(auto x:nums)
	{
		xorr = xorr ^ x;
		if(xorr==target)
			count++;
		if(mp.find(xorr^target)!=mp.end())
		{
			count+=mp[xorr^target];
		}
		mp[xorr]+=1;
	}
	cout<<count<<endl;
	return 0;
}