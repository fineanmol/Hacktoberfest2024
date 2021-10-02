#include <bits/stdc++.h>

using namespace std;

int minimumNumberOfDeletions(string s1) 
    {
        string s2;
        int n = s1.size();
        for(int i=n-1; i>=0; i--)
            s2.push_back(s1[i]);
            
        int t[n+1][n+1];
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(i == 0 || j == 0)
                    t[i][j] = 0;
            }
        }
        
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(s1[i-1] == s2[j-1])
                    t[i][j] = 1 + t[i-1][j-1];
                else
                    t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }
        
        return (n - t[n][n]);
    } 


int main()
{
     string s;
     cin>>s;
     
     cout<<minimumNumberOfDeletions(s)<<endl;
}
