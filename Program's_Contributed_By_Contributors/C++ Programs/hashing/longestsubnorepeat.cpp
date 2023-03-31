#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s = "abcaabcda";
	vector<int> vals(256,-1);
	int l = 0, r = 0;
	int n = s.length();
	int len = 0;
	while(r<n)
	{
		if(vals[s[r]]!=-1)
			l = max(l, vals[s[r]]+1);
		vals[s[r]] = r;
		len = max(len, r-l+1);
		r++;
	}
	cout<<len<<endl;
	return 0;

}