
import java.util.*;

public class SelectionSort {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int[] arr = { 4, 6, 7, 2, 1, 5, 3, 8, 9 };
		selectionSorting(arr);
		System.out.println(Arrays.toString(arr));

	}

	static void selectionSorting(int[] arr) {
		for (int i = 0; i < arr.length; i++) {
//			find the max item in the remaining array and swap with correct index

			int last = arr.length - i - 1;

			int maxInd = getMaxInd(arr, 0, last);
			swapArray(arr, maxInd, last);
		}
	}

	private static int getMaxInd(int[] arr, int start, int end) {
		int max = start;

		for (int i = start; i <= end; i++) {
			if (arr[max] < arr[i])
				max = i;
		}
		return max;
	}

	static void swapArray(int[] arr, int first, int second) {
		int temp = arr[first];
		arr[first] = arr[second];
		arr[second] = temp;
	}

}
