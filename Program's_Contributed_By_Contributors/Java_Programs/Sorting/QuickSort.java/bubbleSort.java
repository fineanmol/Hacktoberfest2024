public class Sorting
{
    public int[] bubbleSort(int[] nums) {
        // snippet of the code
        int l= nums.length;
        int t=0; //temporary variable

        for (int i = 0; i < l - 1; i++) {
    
            for (int j = 0; j < l - 1 - i; j++) //no need to go till last element, just see the last fixed element
            {
                if (nums[j] > nums[j + 1]) //compare consecutive elements
                {
    
                    t = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = t;
                }
            }
        }

        return nums;
    }
}



