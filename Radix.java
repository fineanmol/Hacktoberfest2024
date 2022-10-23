//Radix Sort implementation
import java.util.Scanner;
import java.util.Arrays;

class Radix {

    // An utility function to find the maximum element 
	static int findMaxElement(int arr[], int n)
	{
		int mx = arr[0];
		for (int i = 1; i < n; i++)
			if (arr[i] > mx)
				mx = arr[i];
		return mx;
	}

	static void countingSort(int arr[], int n, int exp)
	{
		int output[] = new int[n];
        int count[] = new int[10];
        int i;
		Arrays.fill(count, 0);

		// Storing the count of all occurences
		for (i = 0; i < n; i++)
			count[(arr[i] / exp) % 10]++;

		// Change count[i] so that count[i] now contains actual position of this digit in output[]
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];

		// Building the output array
		for (i = n - 1; i >= 0; i--) {
			output[count[(arr[i] / exp) % 10] - 1] = arr[i];
			count[(arr[i] / exp) % 10]--;
		}

		//Copying contents back to arr from output array
		for (i = 0; i < n; i++)
			arr[i] = output[i];
	}

	//Performing Radix Sort
	static void radixsort(int arr[], int n)
	{
		// Finding the maximum number in the array to know the number of digits
		int m = findMaxElement(arr, n);

		//Implementing Counting sort for each digit
		for (int exp = 1; m / exp > 0; exp *= 10)
			countingSort(arr, n, exp);
	}

    //Driver Function
	public static void main(String[] args)
	{
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the number of elements in the array - ");
        int n = sc.nextInt();

        int arr[] = new int[n];

        System.out.println("Enter array elements - ");
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();

        radixsort(arr, n);

        for (int i = 0; i < n; i++)
            System.out.print(arr[i] + " ");

        sc.close();
	}
}
