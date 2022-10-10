#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> vals={2,6,3,11,7,4,9,7,10,6};
	int target = 20;

	sort(vals.begin(),vals.end());
	for(int i=0;i<vals.size();i++)
	{
		int x = vals[i];
		int l = i+1;
		int r = vals.size()-1;
		while(l<r)
		{
			if(x+vals[l]+vals[r]==target)
			{
				cout<<"Triplet Found: "<<x<<" "<<vals[l]<<" "<<vals[r]<<endl;
				return 0;
			}
			if(x+vals[l]+vals[r]>target)
			{
				r--;
			}
			else
			{
				l++;
			}
		}
	}

	cout<<"No triplet"<<endl;
	return 0;
}