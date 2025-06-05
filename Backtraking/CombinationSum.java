import java.util.*;

public class CombinationSum {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();
        int[] nums = new int[n];
        System.out.println("Enter elements: ");
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        System.out.print("Enter target sum: ");
        int target = sc.nextInt();
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);
        findCombinations(nums, 0, target, new ArrayList<>(), result);
        System.out.println("Combinations that sum to " + target + ": " + result);
    }

    static void findCombinations(int[] nums, int index, int target, List<Integer> current, List<List<Integer>> result) {
        if (target == 0) {
            result.add(new ArrayList<>(current));
            return;
        }
        for (int i = index; i < nums.length; i++) {
            if (nums[i] > target) break;
            if (i > index && nums[i] == nums[i - 1]) continue; // Skip duplicates
            current.add(nums[i]);
            findCombinations(nums, i, target - nums[i], current, result); // Not i+1 since we can reuse same element
            current.remove(current.size() - 1);
        }
    }
}
