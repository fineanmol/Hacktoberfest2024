// Disjoint Set Implementation - Perfect
// worst time complexity of find and union is O(n)
// Improved time complexity with union by rank and path compressin - O(logn)
#include<bits/stdc++.h>
using namespace std;


// find function
int dsfind(vector<int > &parent, int x)// with path compression
{
	if(parent[x]==x)
	return x;
	
	int res = dsfind(parent, parent[x]);
	parent[x] = res;
	return res;
}

// union function
void dsunion(vector<int > &parent, vector<int > &rank, int x, int y)// (union by rank) with respect to rank (smaller rank under bigger rank, rank increase in case of equal)
{
	int parentx = dsfind(parent, x);
	int parenty = dsfind(parent, y);
	
	if(parentx==parenty)
	return;
	
	if(rank[parentx]<rank[parenty])
	parent[parentx] = parenty;
	else if(rank[parentx]>rank[parenty])
	parent[parenty] = parentx;
	else
	{
		parent[parentx] = parenty;// or reverse
		rank[parenty]++;
	}
}


int main() 
{
	int n = 11;
	
	vector<int > parent(n), rank(n), size(n);// by default array element will be 0
	
	// initiaize parent, rank, and size array
	for(int i=0;i<n;i++)
	{
		parent[i]=i;
		rank[i]=0;
		size[i]=0;
	}
	
	//forming disjoint set
	dsunion(parent, rank, 0, 1);
	dsunion(parent, rank, 1, 2);
	dsunion(parent, rank, 2, 3);
	dsunion(parent, rank, 4, 5);
	dsunion(parent, rank, 5, 6);
	dsunion(parent, rank, 6, 7);
	dsunion(parent, rank, 7, 8);
	dsunion(parent, rank, 9, 10);
	
	// Q.1) finding total no of groups
	//		traverse parent array, find the parent of each parent[i], and insert in the set, return size of set.
	set<int > st;
	for(int i=0;i<n;i++)
	{
		st.insert(dsfind(parent, parent[i]));
	}
	cout<<st.size()<<endl;
	
	// Q.2) print all the groups present
	unordered_map<int, vector<int >> mp;
	for(int i=0;i<n;i++)
	{
		mp[dsfind(parent, parent[i])].push_back(i);
	}
	for(auto it : mp)
	{
		cout<<it.first<<" -> ";// parent
		for(int i=0;i<it.second.size();i++)
		{
			cout<<it.second[i]<<" ";
		}
		cout<<endl;
	}
	
	
	return 0;
}
