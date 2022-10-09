#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> price = {7,1,5,3,6,4};
	int mn =INT_MAX;
	int profit = 0;
	for(int i=0;i<price.size();i++)
	{
		mn = min(mn, price[i]);
		profit = max(profit, price[i]-mn);
	}
	cout<<profit<<endl;

	return 0;
}