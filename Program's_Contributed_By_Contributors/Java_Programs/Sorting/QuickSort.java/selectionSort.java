public class Sorting1 {
    public int[] selectionSort(int[] nums) {
        // snippet of the code
        int l = nums.length;
        int t = 0; //temporary variable

        int min=0;

        for (int i = 0; i < l - 1; i++) 
        {
            min = i; 
            for (int j = i + 1; j < l; j++) {
                if (nums[min] > nums[j]) 
                {
                    //reassign minimum
                    min = j;
                }
                //swapping
                t = nums[min]; 
                nums[min] = nums[i];
                nums[i] = t;

            }
        }

        return nums;
    }
}