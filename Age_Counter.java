
import java.util.Scanner;
import java.time.LocalDate;
import java.time.Period;

public class Calculator {

    public static void main(String[] args) {

        Scanner bday=new Scanner(System.in);

        //Get Inputs
        System.out.println("Enter Your Birth Year");
        int year=bday.nextInt();

        System.out.println("Enter Your Birth Month");
        int month=bday.nextInt();

        System.out.println("Enter Your Birth Date");
        int day=bday.nextInt();



        LocalDate pres = LocalDate.now();
        LocalDate bdate = LocalDate.of(year,month,day);

        int age = Period.between(bdate , pres).getYears();

        System.out.println("Current Date");
        System.out.println(pres);
        System.out.println("Birth Date");
        System.out.println(bdate);
        System.out.println("Your Age");
        System.out.println(age);
    }

)
