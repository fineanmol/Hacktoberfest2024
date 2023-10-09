import java.util.Arrays;

public class CocktailShakerSort {
    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};

        System.out.println("Original array: " + Arrays.toString(arr));

        cocktailShakerSort(arr);

        System.out.println("Sorted array: " + Arrays.toString(arr));
    }

    public static void cocktailShakerSort(int[] arr) {
        int left = 0;
        int right = arr.length - 1;
        boolean swapped;

        do {
            swapped = false;

            // Perform a bubble sort from left to right
            for (int i = left; i < right; i++) {
                if (arr[i] > arr[i + 1]) {
                    // Swap arr[i] and arr[i+1]
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                    swapped = true;
                }
            }

            if (!swapped) {
                // If no swaps occurred, the array is already sorted
                break;
            }

            swapped = false;
            right--;

            // Perform a bubble sort from right to left
            for (int i = right; i >= left; i--) {
                if (arr[i] > arr[i + 1]) {
                    // Swap arr[i] and arr[i+1]
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                    swapped = true;
                }
            }

            left++;
        } while (swapped);
    }
}
