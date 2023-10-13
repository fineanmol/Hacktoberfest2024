import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class BucketSort {

    public static void main(String[] args) {
        double[] arr = {0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51};
        
        System.out.println("Original Array:");
        printArray(arr);

        bucketSort(arr);

        System.out.println("Sorted Array:");
        printArray(arr);
    }

    public static void bucketSort(double[] arr) {
        int n = arr.length;
        if (n <= 0) return;

        @SuppressWarnings("unchecked")
        List<Double>[] buckets = new ArrayList[n];

        for (int i = 0; i < n; i++) {
            buckets[i] = new ArrayList<>();
        }

        for (int i = 0; i < n; i++) {
            int bucketIndex = (int) (n * arr[i]);
            buckets[bucketIndex].add(arr[i]);
        }

        for (int i = 0; i < n; i++) {
            Collections.sort(buckets[i]);
        }

        int index = 0;
        for (int i = 0; i < n; i++) {
            for (double value : buckets[i]) {
                arr[index] = value;
                index++;
            }
        }
    }

    public static void printArray(double[] arr) {
        for (double value : arr) {
            System.out.print(value + " ");
        }
        System.out.println();
    }
}
