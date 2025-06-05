//tested on: https://www.hackerrank.com/challenges/dijkstrashortreach
// Complexity = O(ElogV)
// Faster Dijkstra on Special Graphs : http://codeforces.com/blog/entry/43508

#include <bits/stdc++.h>

using namespace std;

# define INF 0x3f3f3f3f
typedef pair<int, int> pii;

vector < pair <int,int> > alist[100005];

int n,m;

void dijkstra (int src)
{
	priority_queue < pii, vector <pii>, greater<pii> > pq;
	vector <int> dist(n+1,INF);
	pq.push({0,src});
	dist[src] = 0;

	while(!pq.empty())
	{
		pii u = pq.top();
		pq.pop();

		for(pii i : alist[u.second])
		{
			
			if(dist[i.first]>dist[u.second] + i.second)
			{
				dist[i.first] = dist[u.second] + i.second;
				pq.push({dist[i.first],i.first});
				
			}
		

		}
	}

	for(int i = 1; i <= n ; i++)
	{
		if(i == src)
			continue;
		if(dist[i] == INF)
			cout << "-1 ";
		else
			cout << dist[i] << ' ';
	}
	cout << endl;


}

int main()
{
	//ios::sync_with _stdio(false);

	int t;

	cin >> t;

	while(t--)
	{
		cin >> n >> m;
	
		for(int i=1;i<=n;i++)
			alist[i].clear();
		
		for(int i=0;i<m;i++)
		{
			int a,b,w;
			cin >> a >> b >> w;
			alist[a].push_back({b,w});
			alist[b].push_back({a,w});
		}
		
		int s;
		cin >> s;
		dijkstra(s);
	}
	return 0;

}
