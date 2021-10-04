
import java.util.*;

public class InsertionSort {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int[] arr = { 5, 3, 4, 1, 2 };
		insertionSorting(arr);
		System.out.println(Arrays.toString(arr));

	}

	static void insertionSorting(int[] arr) {
		for (int i = 0; i < arr.length - 1; i++) {
			for (int j = i + 1; j > 0; j--) {
				if (arr[j] < arr[j - 1]) {
					swapArray(arr, j, j - 1);
				} else {
					break;
				}
			}
		}
	}

	static void swapArray(int[] arr, int first, int second) {
		int temp = arr[first];
		arr[first] = arr[second];
		arr[second] = temp;
	}

}
