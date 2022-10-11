#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> arr = {120,200,50,700,850,550};
	vector<int> dep = {550,600,500,900,1000,700};
	for(auto x:arr)
		cout<<x<<" ";
	cout<<endl;
	for(auto x:dep)
		cout<<x<<" ";
	cout<<endl;
	sort(arr.begin(), arr.end());
	sort(dep.begin(), dep.end());
	int i = 0;
	int j = 0;
	int curr = 0;
	int mx = 0;


	while(i<arr.size() and j<arr.size())
	{
		if(arr[i]<=dep[j])
		{
			curr++;
			i++;
		}
		else if(arr[i]>dep[j])
		{
			curr--;
			j++;
		}
		mx = max(mx,curr);
	}
	cout<<mx<<endl;
	return 0;
}