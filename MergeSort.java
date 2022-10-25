import java.util.Arrays;

public class MergeSort {
    public static void main(String[] args) {
        int[] arr = {2, 8, 99, 76, 54, -1, 76, 43, 40};
        mergeSort(arr, 0, arr.length-1);
        System.out.print(Arrays.toString(arr));
    }

    static void mergeSort(int[] arr, int s, int l) {
        if(s < l) {
            int mid = s + (l-s)/2;
            mergeSort(arr, s, mid);
            mergeSort(arr, mid+1, l);
            merge(arr, s, mid, l);
        }
    }

    static void merge(int[] arr, int s, int m, int l) {
        int[] left = new int[m-s+1];
        int[] right = new int[l-m];
        for(int i = 0; i<m-s+1; i++) {
            left[i] = arr[s+i];
        }
        for(int j = 0; j<l-m; j++) {
            right[j] = arr[m+j+1];
        }
        int i = 0, j = 0, k = s;
        while(i < left.length && j < right.length) {
            if(left[i] <= right[j]) {
                arr[k] = left[i];
                i++;
            }
            else {
                arr[k] = right[j];
                j++;
            }
            k++;
        }
        while(i < left.length) {
            arr[k] = left[i];
            i++;
            k++;
        }
        while(j < right.length) {
            arr[k] = right[j];
            j++;
            k++;
        }
    }
}