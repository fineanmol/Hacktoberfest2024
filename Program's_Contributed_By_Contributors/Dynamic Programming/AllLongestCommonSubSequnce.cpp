#include<bits/stdc++.h>
using namespace std;

int lookup[100][100];

void longestsub(string s1,string s2)
{
	int n1=s1.length(),n2=s2.length();
	for(int i=0;i<=n1;i++)
		for(int j=0;j<=n2;j++)
			if(i==0 || j==0)
				lookup[i][j]=0;
			else if(s1[i-1]==s2[j-1])
				lookup[i][j]=lookup[i-1][j-1]+1;
			else
				lookup[i][j]=max(lookup[i][j-1],lookup[i-1][j]);
}

vector<string> LCS(string X,string Y,int m,int n)
{
    if(m==0 || n==0)
    {
        vector<string>v(1);
        return v;
    }
    if(X[m-1]==Y[n-1])
    {
        vector<string>lcs=LCS(X,Y,m-1,n-1);
        for(string &str:lcs)
            str.push_back(X[m-1]);
        return lcs;
    }
    if(lookup[m-1][n]>lookup[m][n-1])
        return LCS(X,Y,m-1,n);
    if(lookup[m][n-1]>lookup[m-1][n])
        return LCS(X,Y,m,n-1);
    vector<string>top=LCS(X,Y,m-1,n);
    vector<string> left=LCS(X,Y,m,n-1);
    top.insert(top.end(),left.begin(),left.end());
    return top;
}

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	longestsub(s1,s2);
	set<string>uniq;
	vector<string>ans=LCS(s1,s2,s1.length(),s2.length());
	for(auto val:ans)
		uniq.insert(val);
	for(auto val:uniq)
		cout<<val<<endl;
	return 0;
}

/*
Sample Input:
ABCBDAB
BDCABA
Sample Output:
BCAB
BCBA
BDAB
*/
