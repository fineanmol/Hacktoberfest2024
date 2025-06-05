import java.util.*;

public class SubsetSum {
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
        findSubsets(nums, 0, target, new ArrayList<>(), result);
        System.out.println("Subsets that sum to " + target + ": " + result);
    }

    static void findSubsets(int[] nums, int index, int target, List<Integer> current, List<List<Integer>> result) {
        if (target == 0) {
            result.add(new ArrayList<>(current));
            return;
        }
        if (index == nums.length || target < 0) return;

        current.add(nums[index]);
        findSubsets(nums, index + 1, target - nums[index], current, result);
        current.remove(current.size() - 1);
        findSubsets(nums, index + 1, target, current, result);
    }
}
