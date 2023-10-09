import java.util.Arrays;

public class CycleSort {
    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};

        System.out.println("Original array: " + Arrays.toString(arr));

        cycleSort(arr);

        System.out.println("Sorted array: " + Arrays.toString(arr));
    }

    public static void cycleSort(int[] arr) {
        int n = arr.length;

        for (int currentIndex = 0; currentIndex < n - 1; currentIndex++) {
            int item = arr[currentIndex];
            int position = currentIndex;

            // Find the correct position for the current element
            for (int i = currentIndex + 1; i < n; i++) {
                if (arr[i] < item) {
                    position++;
                }
            }

            // If the current element is already in the correct position, skip it
            if (position == currentIndex) {
                continue;
            }

            // Move the cycle of elements to the correct position
            while (item == arr[position]) {
                position++;
            }

            int temp = arr[position];
            arr[position] = item;
            item = temp;

            // Rotate the rest of the cycle
            while (position != currentIndex) {
                position = currentIndex;

                for (int i = currentIndex + 1; i < n; i++) {
                    if (arr[i] < item) {
                        position++;
                    }
                }

                while (item == arr[position]) {
                    position++;
                }

                temp = arr[position];
                arr[position] = item;
                item = temp;
            }
        }
    }
}
