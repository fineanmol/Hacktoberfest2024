public class Quick_Sort {
    public int partion(int[] nums, int low, int high) {
        int i = low, j = high, pivot = nums[low];
        while (i < j) {
            while (nums[i] <= pivot && i <= high - 1)
                i++;
            while (j >= low + 1 && nums[j] > pivot)
                j--;
            if (i < j) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
        int temp = nums[low];
        nums[low] = nums[j];
        nums[j] = temp;
        return j;

    }

    public void quicksort(int[] nums, int low, int high) {
        if (low < high) {
            int p = partion(nums, low, high);
            quicksort(nums, low, p - 1);
            quicksort(nums, p + 1, high);
        }
    }

    public int[] sortArray(int[] nums) {
        quicksort(nums, 0, nums.length - 1);
        return nums;
    }
}
