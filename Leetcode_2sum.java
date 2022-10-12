class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] ans = new int[2];
        HashMap< Integer, Integer> map = new HashMap<>();
        for(int i =0;i<nums.length;i++){
            
                map.put(nums[i], i);
        
        }
        for(int i=0;i<nums.length;i++){
            int cur = nums[i];
            int req = target - cur;
            if(map.containsKey(req) && map.get(req) != i){  // map will store the second occurance of the value so it will solve the corner case 
                ans[0] = i;
                ans[1] = map.get(req);
            }
        }
        return ans;
    }
}
