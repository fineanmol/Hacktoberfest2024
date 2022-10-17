import java.util.Scanner;

public class LargestOfAll{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a,b,c;
        a=sc.nextInt();
        b=sc.nextInt();
        c=sc.nextInt();

        if(a>b && a>c){
            System.out.println(a+" is the greatest.");    
        }
        else if(b>a && b>c){
            System.out.println(b+" is the greatest.");
        }
        else{
            System.out.println(c+" is the greatest.");
        }
    }
}