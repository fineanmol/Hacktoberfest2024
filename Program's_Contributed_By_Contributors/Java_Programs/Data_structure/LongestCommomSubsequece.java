class Solution
{
    static int lcs(int x, int y, String s1, String s2)
    {
        int dp[][]= new int[x+1][y+1];
       for(int i = 0; i<=x; i++) {
			Arrays.fill(dp[i], -1);
		}
		
		int ans =lcsdprer(x,y,s1,s2,dp);
		return ans;

    }
    static int lcsdprer(int x, int y, String s1, String s2,int dp[][]){
        if(x==0 || y==0){
            return 0;
        }
        if(dp[x][y] !=-1){
            return dp[x][y];
        } 
        if(s1.charAt(x-1)==s2.charAt(y-1)){
            return dp[x][y]=lcsdprer(x-1,y-1,s1,s2,dp) + 1;
        }
        else{
            return dp[x][y]= Math.max(lcsdprer(x-1,y,s1,s2,dp),lcsdprer(x,y-1,s1,s2,dp));
        }
    }

    
}
