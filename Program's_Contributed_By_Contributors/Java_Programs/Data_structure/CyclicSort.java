class Solution {
    public int missingNumber(int[] nums) {
        // Sort the Array Using Cyclic Sort
        cyclicSort(nums);
        // Now Iterate Over the Array and Find the Element which is not at the Correct Position
        for(int i=0; i<nums.length; i++){
            if(i != nums[i])
                return i;
        }
        return nums[nums.length - 1] +1;
    }
    static void cyclicSort(int [] nums){
        for(int i=0; i<nums.length; ){
            if(nums[i] >= nums.length || i == nums[i])
                i++;
            else 
                swap(nums, i, nums[i]);
        }
    }
    
    static void swap(int [] nums, int a, int b){
        int temp = nums[a];
        nums[a]  = nums[b];
        nums[b]  = temp;
    }
}
