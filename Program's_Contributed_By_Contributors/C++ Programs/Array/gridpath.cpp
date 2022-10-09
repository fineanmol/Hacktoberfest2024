#include<bits/stdc++.h>
using namespace std;

int main()
{
	int m = 5;
	int n = 4;
	int N = m+n-2;
	int r = m-1;
	int res = 1;
	for(int i=0;i<r;i++)
	{
		res*=(N-r+i+1);
		res/=(i+1);

	}
	cout<<res<<endl;
    return 0;
}