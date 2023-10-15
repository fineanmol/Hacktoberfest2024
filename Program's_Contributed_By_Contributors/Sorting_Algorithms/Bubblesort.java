// implementation of Bubble sort in java

import java.io.*;
import java.util.Scanner;


class Bubblesort
 {
	static void bubbleSort(int arr[], int n)
	{
		int i, j, temp;
		boolean swapped;
		for (i = 0; i < n - 1; i++) {
			swapped = false;
			for (j = 0; j < n - i - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
					swapped = true;
				}
			}

			if (swapped == false)
				break;
		}
	}

	// Function to print an array
	static void printArray(int arr[], int size)
	{
		int i;
		for (i = 0; i < size; i++)
			System.out.print(arr[i] + " ");
		System.out.println();
	}

	// Driver program
	public static void main(String args[])
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

		bubbleSort(arr, n);
		System.out.println("Sorted array: ");
		printArray(arr, n);
	}
}

// This code is contributed
// by Vinayak kushwah
// #Hacktoberfest2023