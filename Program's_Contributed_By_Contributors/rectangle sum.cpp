//saurabh kumar
//https://github.com/saurabhkumar1432
//date-1 october 2022 
//time - 00:26
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
         int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dp[i+1][j]=dp[i][j]+matrix[i][j];
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<m;i++){
            for(int l=i+1;l<=m;l++){
                for(int j=0;j<n;j++){
                    int val=0;
                    for(int k=j;k<n;k++){
                        val+=dp[l][k]-dp[i][k];
                        
                        if(val<k){
                            ans=max(ans,val);
                        }
                        else if(val==k){
                            return k;
                        }
                    }
                }
            }
        }
        return ans;
    
    }
};
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
         int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dp[i+1][j]=dp[i][j]+matrix[i][j];
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<m;i++){
            for(int l=i+1;l<=m;l++){
                for(int j=0;j<n;j++){
                    int val=0;
                    for(int k=j;k<n;k++){
                        val+=dp[l][k]-dp[i][k];
                        
                        if(val<k){
                            ans=max(ans,val);
                        }
                        else if(val==k){
                            return k;
                        }
                    }
                }
            }
        }
        return ans;
    
    }
};