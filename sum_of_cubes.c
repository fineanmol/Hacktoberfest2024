// C program for the above approach
#include <stdio.h>

// Function to calculate the sum of cubes of numbers from 1
// to n
int sumOfCubes(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		// Cube of the current number is added to the sum
		sum += i * i * i;
	}
	return sum;
}

// Driver Code
int main()
{
	// Set the value of n
	int n = 5;
	// Calculate the sum of cubes
	int result = sumOfCubes(n);
	printf("%d\n", result);
	return 0;
}
