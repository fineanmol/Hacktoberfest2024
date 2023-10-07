
public class Counting_Sort {
    public int[] sortArray(int[] nums) {
        int[] count = new int[10];
        int ans[] = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            count[nums[i]]++;
        }
        for (int i = 1; i < count.length; i++) {
            count[i] += count[i - 1];
        }
        for (int i = nums.length - 1; i >= 0; i--) {
            int a = count[nums[i]];
            ans[a - 1] = nums[i];
            count[nums[i]]--;
        }
        return ans;
    }
}
