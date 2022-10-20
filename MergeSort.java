import java.util.*;


public class MergeSort {
	public static int[] acceptArray() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the Size of array: ");
        int n = sc.nextInt();
        int arr[] = new int[n];
        System.out.println("Enter the elements of array: ");
        for (int i = 0; i < arr.length; i++) {
            arr[i] = sc.nextInt();

        }
        
        return arr;
        

    }
	public static void printArray(int arr[]) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");

        }

    }
	public static int[] mergeSort(int inp[]) {
		if(inp.length<=1) {
			return inp;
		}
		int iin = (inp.length)/2;
		int left[] = mergeSort(Arrays.copyOfRange(inp, 0, iin));
		int right[] = mergeSort(Arrays.copyOfRange(inp, iin, inp.length));
		return mergeMethod(left, right);
	}
	public static int[] mergeMethod(int left[], int right[]) {
	int i=0;
	int j=0;
	int newArr[] = new int[left.length+right.length];
	int k=0;
	while(i<left.length&&j<right.length) {
		if(left[i]<right[j]) {
			newArr[k] = left[i];
			i++;
			k++;
		}
		else {
			newArr[k] = right[j];
			k++;
			j++;
		}
	}
	while(i<left.length) {
		newArr[k] = left[i];
		k++;
		i++;
	}
	while(j<right.length) {
		newArr[k] = right[j];
		j++;
		k++;
	}
	return newArr;
	}
	public static void main(String[] args) {
		int arr[] = acceptArray();
		printArray(arr);
		
		int newArr[] = mergeSort(arr);
		System.out.println("\nThe sorted array is: ");
		for(int i : newArr) {
			System.out.print(i+" ");
		}
		System.out.println();
	}
	
}
