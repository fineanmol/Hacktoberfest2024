
// package selectionSort;
import java.util.Scanner;

public class SelectionSort {
	public static void main(String args[]) {
		long start = System.currentTimeMillis();
		Scanner scanner = new Scanner(System.in);

		System.out.println("Enter the  the size of array ");
		int size = scanner.nextInt();

		int[] arr = new int[size];

		System.out.println("Enter the aray  elements one by one ");
		for (int i = 0; i < size; i++) {
			arr[i] = scanner.nextInt();
		}
		SelectionSort(arr);

		System.out.println("array: ");
		for (int i = 0; i < size; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println(" ");
		long duration = (System.currentTimeMillis() - start);
		System.out.println(duration + "ms");
		scanner.close();
	}

	private static void SelectionSort(int[] arr) {
		int n = arr.length;
		for (int i = 0; i < n - 1; i++) {
			int min = i;
			for (int j = i + 1; j < n; j++) {
				if (arr[min] > arr[j]) {
					min = j;
				}
			}
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}
/*
 * 78
 * 45
 * 1
 * 795
 * 4
 */