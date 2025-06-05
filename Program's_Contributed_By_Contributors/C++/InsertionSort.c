// C program for insertion sort
//contributed by @whyanujjwhy
#include <math.h>
#include <stdio.h>

void insertionSort(int arr[], int n)
{
	int i, j, key;
	for (i=1; i<n; i++) {
		key=arr[i];
		j=i-1;

		// Move elements of arr[0..i-1], that are
		//greater than key, to one position left
		//to their current position 
		while(j>=0 && arr[j]>key) {
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}

// A function to print the array
void printArray(int arr[], int n) {
	int i;
	for(i=0; i<n; i++)
		printf("%d ", arr[i]);

	printf("\n");
}

/* Driver program to test insertion sort */
int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

	insertionSort(arr, n);
	printArray(arr, n);

	return 0;
}
