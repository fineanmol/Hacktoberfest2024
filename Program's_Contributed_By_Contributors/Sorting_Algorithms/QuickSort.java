//  implementation of QuickSort
import java.io.*;
import java.util.Scanner;


class QuickSort {

	static void swap(int[] arr, int i, int j)
	{
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	static int partition(int[] arr, int low, int high)
	{
		// Choosing the pivot
		int pivot = arr[high];

		// Index of smaller element and indicates the right position of pivot found so far
		int i = (low - 1);

		for (int j = low; j <= high - 1; j++) {

			// If current element is smaller than the pivot
			if (arr[j] < pivot) {

				// Increment index of smaller element
				i++;
				swap(arr, i, j);
			}
		}
		swap(arr, i + 1, high);
		return (i + 1);
	}

	// The main function that implements QuickSort
	static void quickSort(int[] arr, int low, int high)
	{
		if (low < high) {

			// pi is partitioning index, arr[p]
			// is now at right place
			int pi = partition(arr, low, high);

			// Separately sort elements before
			// partition and after partition
			quickSort(arr, low, pi - 1);
			quickSort(arr, pi + 1, high);
		}
	}
	// To print sorted array
	public static void printArr(int[] arr)
	{
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
	}
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);

		System.out.print("Enter the length of Array = ");
		int n = sc.nextInt();
		int arr[] = new int[n];
		System.out.print("\n Enter the values of array = ");

		for(int i =0; i<n;i++){
			System.out.print("\n Enter the value of Array at index "+ i +" = ");
			arr[i] =sc.nextInt();
		}
		int N = arr.length;

		// Function call
		quickSort(arr, 0, N - 1);
		System.out.println("Sorted array:");
		printArr(arr);
	}
}

//This code is contributed
// by Vinayak kushwah
// #Hacktoberfest2023

