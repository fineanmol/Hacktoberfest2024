//  implementation of Insertion Sort in java ;
import java.util.Scanner;

public class InsertionSort {
	/*Function to sort array using insertion sort*/
	void sort(int arr[])
	{
		int n = arr.length;
		for (int i = 1; i < n; ++i) {
			int key = arr[i];
			int j = i - 1;

			/* Move elements of arr[0..i-1], that are
			greater than key, to one position ahead
			of their current position */
			while (j >= 0 && arr[j] > key) {
				arr[j + 1] = arr[j];
				j = j - 1;
			}
			arr[j + 1] = key;
		}
	}

	/* A utility function to print array of size n*/
	static void printArray(int arr[])
	{
		int n = arr.length;
		for (int i = 0; i < n; ++i)
			System.out.print(arr[i] + " ");

		System.out.println();
	}

	
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

		InsertionSort ob = new InsertionSort();
		ob.sort(arr);

		printArray(arr);
	}
};


// This code is contributed
// by Vinayak kushwah
// #Hacktoberfest2023
