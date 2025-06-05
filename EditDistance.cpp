// Q174 https://leetcode.com/problems/edit-distance/


// Recursion
// Time: O(3^n)
// Space: O(n) 
class Solution {
    int f(int i,int j, string s1,string s2){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(s1[i]==s2[j]) return f(i-1,j-1,s1,s2);
        return 1+min(f(i,j-1,s1,s2),min(f(i-1,j,s1,s2),f(i-1,j-1,s1,s2)));
    }
public:
    int minDistance(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        return f(n-1,m-1,str1,str2);
        
    }
};

// Memorisation
// Time: O(N*m)
// Space: O(N*M)+O(N) = auxiliary stack space+ dp
class Solution {
    int f(int i,int j, string s1,string s2,vector<vector<int>> &dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]= f(i-1,j-1,s1,s2,dp);
        return dp[i][j]=1+min(f(i,j-1,s1,s2,dp),min(f(i-1,j,s1,s2,dp),f(i-1,j-1,s1,s2,dp)));
    }
public:
    int minDistance(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,str1,str2,dp);
        
    }
};





// DP
// Time: O(N*m)
// Space: O(N*M)
class Solution {
    int f(int i,int j, string s1,string s2,vector<vector<int>> &dp){
        if(i==0) return j;
        if(j==0) return i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i-1]==s2[j-1]) return dp[i][j]= f(i-1,j-1,s1,s2,dp);
        return dp[i][j]=1+min(f(i,j-1,s1,s2,dp),min(f(i-1,j,s1,s2,dp),f(i-1,j-1,s1,s2,dp)));
    }
public:
    int minDistance(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n+1;i++) dp[i][0]=i;
        for(int j=0;j<m+1;j++) dp[0][j]=j;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]= dp[i-1][j-1];
                else 
                    dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
            }
        }
        return dp[n][m];
        
    }
};

  

// TABULATION
// Time: O(N*m)
// Space: O(2*M)
class Solution {
public:
    int minDistance(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<int>p(m+1,0);
        vector<int>c(m+1,0);
        for(int j=0;j<m+1;j++) p[j]=j;
        for(int i=1;i<n+1;i++){
            c[0]=i;
            for(int j=1;j<m+1;j++){
                if(s1[i-1]==s2[j-1]) c[j]= p[j-1];
                else 
                    c[j]=1+min(c[j-1],min(p[j],p[j-1]));
            }
            p=c;
        }
        return p[m];
        
    }
};

// https://youtu.be/fJaKO8FbDdo?t=2204
// SINGLE ARRAY TABULATION   NOTPOSSIBLE AS WE ARE ACCESSING THE PREVIOUS ELEMENTS IN P AS WELL AS C
// LINE NO 94: c[j]= p[j-1]; acccesssing previous element in p
// LINE NO 96: c[j]=1+min(c[j-1],min(p[j],p[j-1])); acccessing previous element in c
// Time: O(N*m)
// Space: O(M)
