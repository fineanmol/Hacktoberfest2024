#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int n,e,k,a,b;

vector <int> friends[305];
bool visited[305];
void bfs(int src)
{
	int v=0;
	memset(visited,0,sizeof(visited));
	queue < pair <int,int> > q;
	q.push(make_pair(src,0));
	int count = 0;
	visited[src] = true;
	while(!q.empty())
	{
		pair<int,int> x = q.front();
		q.pop();
		v++;
		for(int ii=0 ; ii<friends[x.first].size();ii++)
		{
			int i = friends[x.first][ii];
			if(!visited[i] && x.second+1<=k)
			{
				visited[i] = true;
				q.push({i,x.second+1});
			}
		}
	}

	cout << v - friends[src].size() - 1 << endl;
}

int main()
{

	cin >> n >> e >> k;

	int ctr[n] = {};
	for(int i=0;i<e;i++)
	{
		cin >> a >> b;

		friends[a].push_back(b);
		friends[b].push_back(a);

	}

	for(int i=1;i<=n;i++)
	{
		bfs(i);
	}

	return 0;
}
