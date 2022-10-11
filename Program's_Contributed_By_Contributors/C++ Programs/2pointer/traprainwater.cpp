#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> rain = {0,1,0,2,1,0,1,3,2,1,2,1};
	int l = 0;
	int r = rain.size() -1;
	int leftmax = 0;
	int rightmax = 0;
	int res = 0;
	while(l<=r)
	{
		if(rain[l]<=rain[r])
		{
			if(rain[l]>=leftmax)
			{
				leftmax = rain[l];
			}
			else
			{
				res+= leftmax - rain[l];
			}
			l++;
		}
		else
		{
			if(rain[r]>=rightmax)
			{
				rightmax = rain[r];
			}
			else
			{
				res+=rightmax - rain[r];
			}
			r--;
		}
	}
	cout<<res<<endl;
	return 0;
}