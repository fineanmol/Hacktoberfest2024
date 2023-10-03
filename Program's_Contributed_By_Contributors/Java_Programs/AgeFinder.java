import java.time.LocalDate;
import java.util.Scanner;
class AgeFinder{
    public static void main(String[] args) {
        LocalDate year = LocalDate.now();
        Scanner read = new Scanner(System.in);
        System.out.println("Enter the year of Birth:");
        int dob = read.nextInt();
        System.out.println("Your age is "+(year.getYear()-dob)+".");
    }
};
