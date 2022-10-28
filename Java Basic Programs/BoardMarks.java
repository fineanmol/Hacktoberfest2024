// This is a program to find the percantage of a student in his/her boards exams 

import java.util.Scanner;
public class BoardMarks{
    public static void main(String [] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("enter your marks in maths ");
        float mark1=sc.nextInt();
        System.out.println("enter your marks in physics ");
        float mark2=sc.nextInt();
        System.out.println("enter your marks in chemistry  ");
        float mark3=sc.nextInt();
        System.out.println("enter your marks in english  ");
        float mark4=sc.nextInt();
        System.out.println("enter your marks in computer science  ");
        float mark5=sc.nextInt();
        float percantage;
        float sum;
        sum=(mark1+mark2+mark3+mark4+mark5);
        percantage=(sum/500)*100;
        System.out.println("the percantage obtained by the student in his board exam is "+percantage);        
    }
}
