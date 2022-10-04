// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        int a = -100, b = -100;
        unordered_map<string, int> mp;
        for(int i = 0 ; i < n ; i++)
            mp[arr[i]]++;
        for(auto it : mp)
        {
            if(it.second > a)
                a = it.second;
        }
        string res = "";
        for(auto it : mp)
        {
            if(it.second != a && it.second > b)
            {
                res = it.first;
                b = it.second;
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
