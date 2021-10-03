import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashSet;
import java.util.Scanner;

public class JavaDequeue {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		Deque<Integer> deque = new ArrayDeque<Integer>();
		HashSet<Integer> hashSet = new HashSet<Integer>();

		int n = sc.nextInt();
		int m = sc.nextInt();
		int max = 0;

		for (int i = 0; i < n; i++) {
			int tmp = sc.nextInt();
			deque.add(tmp);
			hashSet.add(tmp);

			if (deque.size() == m) {
				max = Math.max(hashSet.size(), max);
				int item = deque.remove();
				if (!deque.contains(item)) {
					hashSet.remove(item);
				}
			}
		}
		System.out.println(max);
		sc.close();
	}
}