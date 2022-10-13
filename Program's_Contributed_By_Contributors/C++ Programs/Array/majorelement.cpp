#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> vals = {7,7,5,1,7,7,5,1,1,5,5,5,5,5,5,1};
	int count = 0;
	int el;
	for(int i=0;i<vals.size();i++)
	{
		if(count==0)
			el = vals[i];
		if(el==vals[i])
			count++;
		else
			count--;
	}
	cout<<el<<endl;
	return 0;
}