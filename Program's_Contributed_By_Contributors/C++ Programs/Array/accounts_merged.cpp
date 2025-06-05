//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Disjoint {
private:
  vector<long long> rank, parent;

public:
  Disjoint(int n) {
    rank.resize(n);
    parent.resize(n);
    for (int i = 0; i < n; i++)
      parent[i] = i;
  }

  int findParent(int node) {
    if (node == parent[node])
      return node;
    return parent[node] = findParent(parent[node]);
  }

  void unionByRank(int u, int v) {
    int pu = findParent(u);
    int pv = findParent(v);

    if (rank[pu] < rank[pv]) 
      parent[pu] = pv;
    else if(rank[pu] > rank[pv])
      parent[pv] = pu;
    else {
      parent[pv] = pu;
      rank[pu]++;
    }
  }
};


class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
  int n = accounts.size();
  Disjoint d(n);

  /* DISTRIBUTNG ON TO INDEX */
  unordered_map<string, int> mp;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < accounts[i].size(); j++) {
      string mail = accounts[i][j];
      if (mp.find(mail) == mp.end())
        mp[mail] = i;
      else
        d.unionByRank(i, mp[mail]);
    }
  }

  /* MERGING */
  vector<string> mergedMail[n];
  for (auto i : mp) {
    string mail = i.first;
    int node = d.findParent(i.second);
    mergedMail[node].push_back(mail);
  }

  vector<vector<string>> ans;
  for (int i = 0; i < n; i++) {
    if (mergedMail[i].size() == 0)
      continue;

    sort(mergedMail[i].begin(), mergedMail[i].end());
    mergedMail[i].insert(mergedMail[i].begin(), accounts[i][0]);
    ans.push_back(mergedMail[i]);
  }

  return ans;
}
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends
