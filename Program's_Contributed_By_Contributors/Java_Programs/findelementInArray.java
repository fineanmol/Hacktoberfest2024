// Brute Force Method
// Java Program to find the element at given index after a
// number of rotations
public class Main {

	public static int findElement(int[] arr, int[][] ranges,
								int rotations, int index)
	{

		// Track of the rotation number
		int n1 = 1;

		// Track of the row index for the ranges[][] array
		int i = 0;

		// Initialize the left side of the ranges[][] array
		int leftRange = 0;

		// Initialize the right side of the ranges[][] array
		int rightRange = 0;

		// Initialize the key variable
		int key = 0;

		while (n1 <= rotations) {

			leftRange = ranges[i][0];
			rightRange = ranges[i][1];
			key = arr[rightRange];
			for (int j = rightRange; j >= leftRange + 1;
				j--) {
				arr[j] = arr[j - 1];
			}

			arr[leftRange] = key;

			n1++;
			i++;
		}

		// Return the element after all the rotations
		return arr[index];
	}

	public static void main(String[] args)
	{
		int[] arr = { 1, 2, 3, 4, 5 };

		// No. of rotations
		int rotations = 2;

		// Ranges according to 0-based indexing
		int[][] ranges = { { 0, 2 }, { 0, 3 } };

		int index = 1;
		System.out.println(
			findElement(arr, ranges, rotations, index));
		;
	}
}
