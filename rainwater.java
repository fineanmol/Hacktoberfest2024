package array;

public class rainwater {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] arr = { 7, 4, 0, 9 };
		rainwater(arr);

	}

	public static void rainwater(int[] arr) {

		int[] lr = new int[arr.length];
		int[] rl = new int[arr.length];

		lr[0] = arr[0];
		for (int i = 1; i < rl.length; i++) {
			if (lr[i - 1] > arr[i]) {
				lr[i] = lr[i - 1];
			} else {
				lr[i] = arr[i];
			}
		}
		rl[arr.length - 1] = arr[arr.length - 1];
		for (int i = arr.length - 2; i >= 0; i--) {
			if (rl[i + 1] > arr[i]) {
				rl[i] = rl[i + 1];
			} else {
				rl[i] = arr[i];
			}
		}
		int sum = 0;
		for (int i = 0; i < rl.length; i++) {
			int min = Math.min(lr[i], rl[i]);
			if (min - arr[i] > 0) {
				sum += min - arr[i];
			}
		}
		System.out.println(sum);
	}

}
