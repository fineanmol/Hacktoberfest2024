import java.util.Arrays;

public class CountingSort {
     public static void main(String[] args) {
        int[] arr = {4, 2, 2, 8, 3};

        System.out.println("Original array: " + Arrays.toString(arr));

        countingSort(arr);

        System.out.println("Sorted array: " + Arrays.toString(arr));
    }

    public static void countingSort(int[] arr) {
        int max = Arrays.stream(arr).max().getAsInt();
        int min = Arrays.stream(arr).min().getAsInt();
        int range = max - min + 1;

        int[] count = new int[range];
        int[] output = new int[arr.length];

        // Initialize the count array
        Arrays.fill(count, 0);

        // Count the occurrences of each element
        for (int num : arr) {
            count[num - min]++;
        }

        // Update the count array to store the position of each element
        for (int i = 1; i < range; i++) {
            count[i] += count[i - 1];
        }

        // Build the output array
        for (int i = arr.length - 1; i >= 0; i--) {
            output[count[arr[i] - min] - 1] = arr[i];
            count[arr[i] - min]--;
        }

        // Copy the sorted elements back to the original array
        System.arraycopy(output, 0, arr, 0, arr.length);
    }
}
