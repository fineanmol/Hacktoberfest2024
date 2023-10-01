import java.util.Arrays;

public class BeadSort {
    public static void beadSort(int[] arr) {
        int max = Arrays.stream(arr).max().getAsInt();
        int[] beads = new int[max * arr.length];

        for (int i = 0; i < arr.length; i++) {
            int num = arr[i];
            for (int j = 0; j < num; j++) {
                beads[i * max + j] = 1;
            }
        }

        for (int j = 0; j < max; j++) {
            int sum = 0;
            for (int i = 0; i < arr.length; i++) {
                sum += beads[i * max + j];
                beads[i * max + j] = 0;
            }

            for (int i = arr.length - sum; i < arr.length; i++) {
                beads[i * max + j] = 1;
            }
        }

        for (int i = 0; i < arr.length; i++) {
            int j;
            for (j = 0; j < max && beads[i * max + j] == 1; j++) {
            }
            arr[i] = j;
        }
    }

    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        beadSort(arr);
        System.out.println("Sorted array: " + Arrays.toString(arr));
    }
}
