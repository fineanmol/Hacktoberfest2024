#include <bits/stdc++.h>
using namespace std;

/*build longest prefix-suffix array for seq to be searched*/
vector<int> LPS(string s)
{
    int n=s.size();
    vector<int> pi(n);
    pi[0]=0;
    for(int i=1;i<n;i++)
    {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
        j = pi[j-1];
        if (s[i] == s[j])
        j++;
        pi[i] = j;
    }
    return pi;
}

/*find all starting index where sub is found*/
vector<int> search(string str, string sub)
{
    vector<int> lps=LPS(sub);
    int i(0),j(0);
    vector<int> ind;
    
    while(i<str.size())
    {
        if(str[i]==sub[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j>0)
                j=lps[j-1];
            else
                i++;
        }
        if(j==sub.size())
        {
            ind.push_back(i-sub.size());
            j=lps[j-1];
        }
    }
    return ind;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
    vector<int> ans=search("anant","ant");
    for(auto it:ans)
        cout<<it<<" ";
    return 0;
}

