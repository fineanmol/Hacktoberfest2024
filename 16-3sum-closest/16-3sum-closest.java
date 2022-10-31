class Solution {
    public int threeSumClosest(int[] nums, int target){
        Arrays.sort(nums);
        
        int len = nums.length-2;
        int fullLen = len+1;
        int sum = Integer.MAX_VALUE;


        for(int i= 0, j = 1, k = fullLen; i < len; ++i, j = i+1, k = fullLen){
            int absSum = Math.abs(sum - target);
            while(j < k){
                int newSum = nums[i] + nums[j] + nums[k];
                if(Math.abs(newSum - target) < absSum){
                    sum = newSum;
                    absSum = Math.abs(sum - target);
                }
                if(target > newSum) ++j;
                else if(target < newSum) --k;
                else return newSum;
            }
        }

        return sum;
    }
}