#include <bits/stdc++.h>
using namespace std;
int LCS(string a,string b,int l,int m)
{
    if(a.size()==0||b.size()==0)
    {
        return 0;
    }
    if(a[0]==b[0])
    {
        return 1 + LCS(a.substr(1, l-1), b.substr(1, m - 1), l - 1, m - 1);
    }
    else
    {
        return max(LCS(a.substr(1, l - 1), b, l - 1, m),LCS(a, b.substr(1, m - 1), l, m - 1));
    }

}
string s = " ";
int LCSDP(string a,string b,int l,int m)
{
    int arr[l + 1][m + 1];
    for (int i = 0; i <=l; i++)
    {
        arr[i][0] = 0;
    }
    for (int i = 0; i <=m; i++)
    {
        arr[0][i] = 0;
    }
    for (int i = 1; i <=l;i++)
    {
        for (int j = 1; j <= m;j++)
        {
            if(a[i-1]==b[j-1])
            {
                arr[i][j] = 1 + arr[i - 1][j - 1];
            }
            else
            {
                arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
            }
        }
    }
    int i = l, j = m;
    while(i!=-1&&j!=-1)
    {
        if(a[i-1]==b[j-1])
        {
            s += a[i-1];
            i--;
            j--;
        }
        else
        {
            if(arr[i][j-1]>arr[i-1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    return arr[l][m];
}
int main()
{
    string a = "aggtab";
    string b = "axtxayb";
    cout << LCS(a, b, 6, 7);
    cout << LCSDP(a, b, 6, 7);
    reverse(s.begin(), s.end());
}