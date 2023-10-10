#include<bits/stdc++.h>
using namespace std;

int main()
{
	int num_rows = 6;
	vector<vector<int>> triangle(num_rows);
	for(int i=0;i<num_rows;i++)
	{
		triangle[i].resize(i+1);
		triangle[i][0]=triangle[i][i]=1;
		for(int j=1;j<i;j++)
		{
			triangle[i][j]= triangle[i-1][j-1] + triangle[i-1][j];
		}
	}
	for(int i=0;i<num_rows;i++)
	{
		for(int j=0;j<triangle[i].size();j++)
		{
			cout<<triangle[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<"5th row"<<endl;
	//vector<int> res(7);
	int res = 1;
	cout<<1<<" ";
	for(int i=0;i<5;i++)
	{
			res*=(5-i);
			res/=(i+1);
		
		cout<<res<<" ";
	}
	cout<<endl;
}
