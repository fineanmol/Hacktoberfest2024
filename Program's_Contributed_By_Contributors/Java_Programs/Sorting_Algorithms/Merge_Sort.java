public class Merge_Sort {
    public static void merge(int low, int high, int mid, int[] arr) {
        int array[] = new int[(high - low) + 1];
        int ptr1 = low;
        int ptr2 = mid + 1;
        int i = 0;
        while (ptr1 <= mid && ptr2 <= high) {

            if (arr[ptr1] <= arr[ptr2]) {
                array[i++] = arr[ptr1];
                ptr1++;
            } else {
                array[i++] = arr[ptr2];
                ptr2++;
            }
        }
        while (ptr1 <= mid) {
            array[i++] = arr[ptr1];
            ptr1++;
        }
        while (ptr2 <= high) {
            array[i++] = arr[ptr2];
            ptr2++;
        }
        for (i = low; i <= high; i++) {
            arr[i] = array[i - low];
        }
        // System.out.println();
        return;
    }

    public static void split(int low, int high, int[] arr) {
        if (low >= high)
            return;
        int mid = (low + high) / 2;
        split(low, mid, arr);
        split(mid + 1, high, arr);
        merge(low, high, mid, arr);
    }

    public static void mergeSort(int[] arr, int n) {
        // Write your code here.
        split(0, n - 1, arr);
    }
}
