#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> nums = {2,6,3,8,1,5,4};
	int target = 9;
	map<int, int> mp;
        for(int i=0;i<nums.size();i++)
        {
            int x = target - nums[i];
            if(mp.find(x)!=mp.end())
            {
                cout<<mp[x]<<" "<<i<<endl;
                return 0;
            }
            else
                mp[nums[i]] = i;
        }
    cout<<"-1 -1"<<endl;
    return 0;
}