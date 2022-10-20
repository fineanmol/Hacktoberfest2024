import java.util.Scanner;

public class gp {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a,r,n,e,gp;
        System.out.println("GP Calculator");
        System.out.println("Enter the fisrt number:");
        a=sc.nextInt();
        System.out.println("Enter the ratio:");
        r=sc.nextInt();
        System.out.println("Enter the n-th term:");
        n=sc.nextInt();
        e=n-1;
        int power= (int)Math.pow(r,e);
        gp=a*power;
        System.out.printf("Gp is %d",gp);
        

    
    
    sc.close();
    }

}