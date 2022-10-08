package Sorting.Cyclic_Sort;

import java.util.Arrays;

public class cyclic {

    public static void main(String[] args) {
        int[] arr = { 3, 5, 2, 1, 4 };
        Cyclic_Sort(arr);
        System.out.println(Arrays.toString(arr));
    }

    static void Cyclic_Sort(int[] arr) {
        int i = 0;

        // here we've used while loop beacuse we've to increament the i only when
        // element is at correct index
        while (i < arr.length) {

            int correct_index = arr[i] - 1;
            // when the element is not at the correct index then & only then swap the
            // position else increament the pointer

            if (arr[i] != arr[correct_index]) {
                int temp = arr[i];
                arr[i] = arr[correct_index];
                arr[correct_index] = temp;
            } else {
                i++;
            }

        }

    }
}
