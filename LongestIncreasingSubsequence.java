class Solution {

   public int lcs(int[] nums, int[] nums2){


       int n = nums.length;
       int m = nums2.length;

       int dp[][] = new int[n+1][m+1];


       for(int i=0; i<n; i++){
            dp[i][0] = 0;
       }

       for(int j=0; j<m; j++){
           dp[0][j] = 0;
       }


       for(int i=1; i<n+1; i++){
           for(int j=1; j<m+1; j++){

               if(nums[i-1] == nums2[j-1]){

                   dp[i][j] = dp[i-1][j-1] + 1;
               }

               else{

                   int ans1 = dp[i-1][j];
                   int ans2 = dp[i][j-1];

                   dp[i][j] = Math.max(ans1, ans2);
               }
           }
       }

       return dp[n][m];
   }


    public int lengthOfLIS(int[] nums) {

        HashSet<Integer> set = new HashSet<>();


        for(int ele : nums){
            set.add(ele);
        }


        int [] nums2 = new int[set.size()];

        int i=0;

        for(int setele : set){
            nums2[i++] = setele;
        }

        Arrays.sort(nums2);


        return lcs(nums, nums2);
        
    }
}
