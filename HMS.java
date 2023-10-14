import java.util.Scanner;
class HMS{
	public static void main(String[]args){
		Scanner sc = new Scanner(System.in);
		int n;
		n=sc.nextInt();
		int hours = n/3600;
		n=n%3600;
		int minutes = n/60;
		n=n%60;
		int second = n;
		System.out.println("There are:");
		System.out.println("H:M:S -"+hours+":"+minutes+":"+second);
	}
}
