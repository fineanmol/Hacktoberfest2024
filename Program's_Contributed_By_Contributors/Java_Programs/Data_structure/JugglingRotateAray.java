class JugglingRotateAray {
	int gcd(int a, int b) {
		if (b==0) return a;
		else return gcd(b, a%b);
	}

	void leftRotate(int arr[], int d) {
		int n = arr.length;
		d %= n;
		int i, j, k, temp;
		int gcd = gcd(d, n);
		for (i=0; i < gcd; i++) {
			temp = arr[i];
			j = i;
			while (true) {
				k = j + d;
				if (k >= n) k -= n;
				if (k == i) break;
				arr[j] = arr[k];
				j=k;
			}
			arr[j] = temp;
		}
	}

	public static void main(String[] args) {
		int arr[] = {1,2,3,4,5,6,7};
		JugglingRotateAray obj = new JugglingRotateAray();
		obj.leftRotate(arr, 2);
		obj.print(arr);
	}

	void print (int arr[]) {
		int n = arr.length;
		for (int i = 0; i < n; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println("");
	}
}