import java.util.ArrayList;

public class SubArrayWithGivenSum {
    static ArrayList<Integer> subarraySum(int[] arr, int n, int s) {
        // Your code here
        ArrayList<Integer> a = new ArrayList<>();
        int sum = 0;
        int j = 0, k = 0;

        while (j < n && k < n) {
            sum += arr[j];
            if (sum == s) {
                a.add(k + 1);
                a.add(j + 1);
                return a;
            } else if (sum < s) {
                j++;
            } else if (sum > s) {
                k++;
                j = k;
                sum = 0;
            }

        }
        a.add(-1);
        return a;
    }

    public static void main(String[] args) {
        int arr[] = { 1, 2, 3, 7, 5 };
        int n = arr.length;
        int sum = 12;
        ArrayList<Integer> res = new ArrayList<>();
        res = subarraySum(arr, n, sum);
        System.out.println(res);

    }
}