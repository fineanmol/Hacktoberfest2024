#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<vector<int>> mat = {{10,20,30,40},{11,21,36,43},{25,29,39,50},{50,60,70,80}};

	int row = 0, col = mat[0].size()-1;
	int target = 42;
	while(row<=mat.size() and col>=0)
	{
		if(mat[row][col]==target)
		{
			cout<<"Found"<<endl;
			return 0;
		}
		if(mat[row][col]>target)
		{
			col--;
		}
		else
		{
			row++;
		}
	}
	cout<<"Not Found"<<endl;
	return 0;
}