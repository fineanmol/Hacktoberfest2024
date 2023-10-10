#include<bits/stdc++.h>
using namespace std;

bool comp(vector<int> a, vector<int> b)
{
	return a[0]>b[0];
}

int main()
{
	vector<int> profit = {25,20,10,65,60,80,22,70};
	vector<int> deadline = {4,4,2,6,5,2,2,6};

	vector<vector<int>> job;
	for(int i=0;i<profit.size();i++)
	{
		vector<int> temp;
		temp.push_back(profit[i]);
		temp.push_back(deadline[i]);
		temp.push_back(i+1);
		job.push_back(temp);
	}
	sort(job.begin(),job.end(),comp);
	vector<int> sequence(7,-1);
	int prof = 0;
	for(int i=0;i<job.size();i++)
	{
		int j = job[i][1];
		while(j>0)
		{
			if(sequence[j]==-1)
			{
				sequence[j] = job[i][2];
				prof += job[i][0];
				break;
			}
			j--;
		}
	}
	cout<<"profit: "<<prof<<endl;
	for(int i = 1;i<sequence.size();i++)
	{
		if(sequence[i]!=-1)
			cout<<sequence[i]<<" ";
	}
	cout<<endl;
	return 0;

}