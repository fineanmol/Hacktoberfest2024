
// import java.util.Arrays;
import java.util.HashMap;

public class majority_Element {
    public static void main(String[] args) {
        int[] nums = { 2, 2, 1, 1, 1, 2, 2 };
        int answer = optimal(nums);
        System.out.println(answer);
    }

    // private static int brute(int[] nums) {
    //     int n = nums.length;
    //     for (int i = 0; i < n; i++) {
    //         int count = 0;
    //         int element = nums[i];
    //         for (int j = 0; j < n; j++) {
    //             if (i != j) {
    //                 if (nums[j] == element) {
    //                     count++;
    //                 }
    //             }
    //             if (count > n / 2) {
    //                 return element;
    //             }
    //         }
    //     }
    //     return -1;
    // }

    // private static int better1(int[] nums) {
    //     Arrays.sort(nums);
    //     if (nums.length <= 1)
    //         return nums[0];
    //     Arrays.sort(nums);
    //     int count = 1;
    //     for (int i = 0; i < nums.length - 1; i++) {
    //         if (nums[i] == nums[i + 1]) {
    //             count++;
    //         } else {
    //             count = 1;
    //         }
    //         if (count > nums.length / 2)
    //             return nums[i];
    //     }
    //     return -1;
    // }

    // private static int better2(int[] nums) {
    //     Arrays.sort(nums);
    //     return nums[nums.length / 2];
    // }

    private static int optimal(int[] nums) {
        if (nums.length <= 1)
            return nums[0];
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(nums[i])) {
                int count = map.get(nums[i]) + 1;
                if (count > nums.length / 2)
                    return nums[i];
                else
                    map.put(nums[i], count);

            } else
                map.put(nums[i], 1);
        }
        return -1;
    }
}
