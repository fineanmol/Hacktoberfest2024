// Java Program to sort an elements
// by bringing Arrays into play

// Main class 
class GFG {

	// Main driver method
	public static void main(String[] args)
	{

		// Custom input array
		int arr[] = { 4, 3, 2, 1 };

		// Outer loop
		for (int i = 0; i < arr.length; i++) {

			// Inner nested loop pointing 1 index ahead
			for (int j = i + 1; j < arr.length; j++) {

				// Checking elements
				int temp = 0;
				if (arr[j] < arr[i]) {

					// Swapping
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}

			// Printing sorted array elements
			System.out.print(arr[i] + " ");
		}
	}
}
