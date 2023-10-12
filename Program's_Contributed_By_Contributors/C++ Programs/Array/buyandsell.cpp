#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>;
	vector<int> price(n);
	for(int i=0;i<n;i++){
		cin>>price[i];
	}
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