import java.util.Arrays;
import java.util.Scanner;

public class MergeSort {

    public static void merge(int[] arr, int left, int mid, int right) {
        int[] a = new int[mid - left + 1];
        int[] b = new int[right - mid];
        int i, j, k = left;
        i = j = 0;
        for (i = 0; i < a.length; i++) {
            a[i] = arr[left + i];
        }
        for (i = 0; i < b.length; i++) {
            b[i] = arr[mid + 1 + i];
        }
        i = j = 0;
        while (i < a.length && j < b.length) {
            arr[k++] = (a[i] <= b[j]) ? a[i++] : b[j++];
        }
        while (i < a.length || j < b.length) {
            arr[k++] = (i < a.length) ? a[i++] : b[j++];
        }
    }

    public static void mergeSort(int[] arr, int left, int right) {

        if (left < right) {
            int mid = (left + right) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in).useDelimiter(",");
        String input = sc.nextLine();
        String[] split = input.split(",");
        int[] arr = new int[split.length];
        for (int i = 0; i < split.length; i++) {
            arr[i] = Integer.parseInt(split[i]);
        }
        mergeSort(arr, 0, arr.length - 1);
        System.out.println("Sorted Array -> " + Arrays.toString(arr));
        sc.close();
    }
}
