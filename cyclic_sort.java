import java.util.Arrays;

public class cyclic_sort {
    public static void swap(int [] arr, int first, int second){
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
    public static void cyclicSort(int [] arr){
        int i = 0;
        while (i< arr.length){
            int correct = arr[i] - 1;
            if (arr[i] != arr[correct]){
                swap(arr,i,correct);
            }
            else {
                i++;
            }
        }

    }
    public static void main(String[] args) {
        int [] arr = {4,5,2,1,3};
        cyclicSort(arr);
        System.out.println(Arrays.toString(arr));

    }
}
