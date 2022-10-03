
import java.util.*;

public class LargestNumber {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int count = 1, max = Integer.MIN_VALUE;
		while (true) {
			System.out.println("Enter a Number : ");
			int input = sc.nextInt();
			if (input > max) {
				max = input;
				count = 1;
			} else if (max == input) {
				count++;
			}
			if (input == 0) {
				System.out.println("The greatest number is : " + max + " and the occurence is : " + count);
				break;
			}
		}
		sc.close();
	}

}
