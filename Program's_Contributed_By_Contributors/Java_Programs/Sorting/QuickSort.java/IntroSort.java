import java.util.Arrays;

public class IntroSort {
    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};

        System.out.println("Original array: " + Arrays.toString(arr));

        introsort(arr);

        System.out.println("Sorted array: " + Arrays.toString(arr));
    }

    public static void introsort(int[] arr) {
        int maxDepth = (int) (2 * Math.log(arr.length) / Math.log(2));
        introsortUtil(arr, 0, arr.length - 1, maxDepth);
    }

    public static void introsortUtil(int[] arr, int low, int high, int maxDepth) {
        if (low < high) {
            if (maxDepth == 0) {
                heapsort(arr, low, high);
            } else {
                int pivotIndex = partition(arr, low, high);
                introsortUtil(arr, low, pivotIndex, maxDepth - 1);
                introsortUtil(arr, pivotIndex + 1, high, maxDepth - 1);
            }
        }
    }

    public static int partition(int[] arr, int low, int high) {
        int pivot = arr[low];
        int i = low - 1;
        int j = high + 1;

        while (true) {
            do {
                i++;
            } while (arr[i] < pivot);

            do {
                j--;
            } while (arr[j] > pivot);

            if (i >= j) {
                return j;
            }

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    public static void heapsort(int[] arr, int low, int high) {
        int n = high - low + 1;

        // Build the heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i + low);
        }

        // Extract elements one by one
        for (int i = n - 1; i >= 0; i--) {
            int temp = arr[low];
            arr[low] = arr[low + i];
            arr[low + i] = temp;

            heapify(arr, i, low);
        }
    }

    public static void heapify(int[] arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;

            heapify(arr, n, largest);
        }
    }
}
