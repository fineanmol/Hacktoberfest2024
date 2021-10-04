
import java.util.*;

public class CyclicSort {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int[] arr = {3, 5, 2, 1, 4};
//		always remember it should be continous
		
		sorting(arr);
		System.out.println(Arrays.toString(arr));

	}

//	Algo :-
//	1. Start looping from i
//	2. Put it at corrct index
//	3. Only move i when the element at i is sorted

	static void sorting(int[] arr) {
		int i = 0;
		while (i < arr.length) {
			int correctInd = arr[i] - 1;
//			this should be the correct index

			if (arr[i] != arr[correctInd]) {
				swap(arr, i, correctInd);
			} else {
				i++;
			}
		}
	}

	static void swap(int[] arr, int first, int second) {
		int temp = arr[first];
		arr[first] = arr[second];
		arr[second] = temp;

	}

}
