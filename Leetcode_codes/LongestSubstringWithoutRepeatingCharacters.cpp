// Longest Substring Without Repeating Characters
#include<bits/stdc++.h>
using namespace std;


int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> mp;
    int j = 0, i = 0;
    int n = s.size();
    int ans = 0;
    while (j < n)
    {
        // cout<<i<<" "<<j<<endl;
        if (mp.count(s[j]) == 0)
        {
            mp[s[j]]++;
            ans = max(ans, j - i + 1);
            j++;
            // cout<<"ans "<<ans<<endl;
        }
        else
        {
            while (s[i] != s[j])
            {
                i++;
                mp[s[i]]--;
            }
            mp[s[i]]--;
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}