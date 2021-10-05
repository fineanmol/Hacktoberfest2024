// Question : De Bruijn Sequence 

// Your task is to construct a minimum-length bit string that contains all possible substrings of length n.
//  For example, when n=2, the string 00110 is a valid solution, because its substrings of length 2 are 00, 01, 10 and 11.

// Input
// The only input line has an integer n.

// Output
// Print a minimum-length bit string that contains all substrings of length n. You can print any valid solution.

#include <bits/stdc++.h> 
using namespace std;
#define pb push_back

unordered_set<string> seen;
vector<int> edges;
string a = "01";

void dfs(string start)
{
    for(int i = 0; i < 2; ++i)
    {
        string str = start + a[i];
        if(seen.find(str) == seen.end())
        {
            seen.insert(str);
            dfs(str.substr(1));
            edges.pb(i);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 

    int n;
    cin >> n;

    string start = string(n - 1, '0');
    dfs(start);

    string ans = "";

    for(int i = 0; i < (1 << n); ++i)
        ans += a[edges[i]];
    ans += start;

    cout << ans << '\n';
}

// Input:
// 2

// Output:
// 00110