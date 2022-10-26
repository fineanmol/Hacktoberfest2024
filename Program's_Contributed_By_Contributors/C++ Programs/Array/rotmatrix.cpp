#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
	for(int i =0;i<matrix.size();i++)
	{
		for(int j = 0;j<=i;j++)
		{
			swap(matrix[i][j],matrix[j][i]);
		}
	}
	for(int i=0;i<matrix.size();i++)
	{
		for(int j=0;j<matrix[0].size()/2;j++)
		{
			swap(matrix[i][j],matrix[i][matrix[0].size()-1-j]);
		}
	}
	for(int i = 0;i<matrix.size();i++)
	{
		for(int j=0;j<matrix[0].size();j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}