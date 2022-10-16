#include<bits/stdc++.h>
using namespace std;

static bool comp(vector<int> a, vector<int> b)
{
	return a[1]<b[1];
}
int main()
{
	vector<int> st = {1,0,3,8,5,8};
	vector<int> fin = {2,6,4,9,7,9};
	for(auto x:st)
		cout<<x<<" ";
	cout<<endl;

	for(auto x:fin)
		cout<<x<<" ";
	cout<<endl;

	vector<vector<int>> dummy;
	for(int i=0;i<st.size();i++)
	{
		vector<int> temp;
		temp.push_back(st[i]);
		temp.push_back(fin[i]);
		temp.push_back(i+1);
		dummy.push_back(temp);
	}
	sort(dummy.begin(), dummy.end(), comp);
	vector<int> ans;
	int end = dummy[0][1];
	ans.push_back(dummy[0][2]);
	for(int i=1;i<dummy.size();i++)
	{
		if(dummy[i][0]>end)
		{
			ans.push_back(dummy[i][2]);
			end = dummy[i][1];
		}
	}
	for(auto x:ans)
		cout<<x<<" ";
	cout<<endl;
	return 0;
}