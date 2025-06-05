public class LinearSearch {
    public static void main(String[] args) {
int[] nums = {23, 45, 65, 77,79,56};
int target = 459;
int ans = linearSearch(nums, target);
        System.out.println(ans);
    }
    // search in the array: return the index if item foud
    // otherwise item not found return - 1
    static int linearSearch(int[] arr, int target) {
        if (arr.length == 0) {
            return -1;
        }
        // run a for loop
        for (int index =0; index < arr.length; index++) {
            // check for element at every index if it is = target
            int element = arr[index];
            if (element == target) {
                return index;
            }

        }
        // this line will execute if non of the above have executd
         return - 1;
    }
