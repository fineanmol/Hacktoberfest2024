import java.util.Arrays;

public class PigeonHoleSort {
    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};

        System.out.println("Original array: " + Arrays.toString(arr));

        pigeonholeSort(arr);

        System.out.println("Sorted array: " + Arrays.toString(arr));
    }

    public static void pigeonholeSort(int[] arr) {
        int min = Arrays.stream(arr).min().getAsInt();
        int max = Arrays.stream(arr).max().getAsInt();
        int range = max - min + 1;

        // Create an array to represent pigeonholes
        int[] pigeonholes = new int[range];
        Arrays.fill(pigeonholes, 0);

        // Count the occurrences of each element
        for (int num : arr) {
            pigeonholes[num - min]++;
        }

        // Traverse the pigeonholes and copy the elements back to the original array
        int index = 0;
        for (int i = 0; i < range; i++) {
            while (pigeonholes[i] > 0) {
                arr[index] = i + min;
                pigeonholes[i]--;
                index++;
            }
        }
    }
}
