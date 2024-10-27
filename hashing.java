// Java program to create HashMap from an array
// by taking the elements as Keys and
// the frequencies as the Values

import java.util.*;

class GFG {

	// Function to create HashMap from array
	static void createHashMap(int arr[])
	{
		// Creates an empty HashMap
		HashMap<Integer, Integer> hmap = new HashMap<Integer, Integer>();

		// Traverse through the given array
		for (int i = 0; i < arr.length; i++) {

			// Get if the element is present
			Integer c = hmap.get(arr[i]);

			// If this is first occurrence of element
			// Insert the element
			if (hmap.get(arr[i]) == null) {
				hmap.put(arr[i], 1);
			}

			// If elements already exists in hash map
			// Increment the count of element by 1
			else {
				hmap.put(arr[i], ++c);
			}
		}

		// Print HashMap
		System.out.println(hmap);
	}

	// Driver method to test above method
	public static void main(String[] args)
	{
		int arr[] = { 10, 34, 5, 10, 3, 5, 10 };
		createHashMap(arr);
	}
}
