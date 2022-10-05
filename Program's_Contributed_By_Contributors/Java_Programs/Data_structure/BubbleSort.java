package array.sorting;

import java.util.Arrays;

public class BubbleSort {
    
    static void BSort(int[] array) {

        for (int i = 0; i < array.length; i++) {

            for (int j = 0; j < array.length - i; j++) {

                if (array[j] < array[i]) {
                    swap(array, j - 1, j);
                }
            }
        }
    }

    static void swap(int[] array, int first , int second) {
        int temp = array[first];
        array[first] = array[second];
        array[second] = temp;
    }

    public static void main(String[] args) {
        int[] arr = {1,4,3,2,5,6,8,9};
        BSort(arr);
        System.out.println(Arrays.toString(arr));
    }

}
