// Java code to implement of the approach 

class GFG { 

	// Function to return the maximum 
	// water that can be stored 
	public static int maxWater(int[] arr, int n) 
	{ 

		// To store the maximum water 
		// that can be stored 
		int res = 0; 

		// For every element of the array 
		// except first and last element 
		for (int i = 1; i < n - 1; i++) { 

			// Find maximum element on its left 
			int left = arr[i]; 
			for (int j = 0; j < i; j++) { 
				left = Math.max(left, arr[j]); 
			} 

			// Find maximum element on its right 
			int right = arr[i]; 
			for (int j = i + 1; j < n; j++) { 
				right = Math.max(right, arr[j]); 
			} 

			// Update maximum water value 
			res += Math.min(left, right) - arr[i]; 
		} 
		return res; 
	} 

	// Driver code 
	public static void main(String[] args) 
	{ 
		int[] arr = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 }; 
		int n = arr.length; 

		System.out.print(maxWater(arr, n)); 
	} 
} 

// This code is contributed by Debidutta Rath
