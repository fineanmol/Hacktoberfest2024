import java.util.Scanner;

class min
{
    public static void main(String args[])   
    {  
    	int cur;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the Amount : ₹");
        cur = sc.nextInt();
        if (cur>500) {
            System.out.println("Count of ₹500 :"+(int)(cur/500));
            cur = cur%500;
        }
        if (cur>200) {
            System.out.println("Count of ₹200 :"+(int)(cur/200));
            cur = cur%200;
        }
        if (cur>100) {
            System.out.println("Count of ₹100 :"+(int)(cur/100));
            cur = cur%100;
        }
        if (cur>50) {
            System.out.println("Count of ₹50 :"+(int)(cur/50));
            cur = cur%50;
        }
        if (cur>10) {
            System.out.println("Count of ₹10 :"+(int)(cur/10));
            cur = cur%10;
        }
        if (cur>5) {
            System.out.println("Count of ₹5 :"+(int)(cur/5));
            cur = cur%5;
        }
        if (cur>2) {
            System.out.println("Count of ₹2 :"+(int)(cur/2));
            cur = cur%2;
        }
        if (cur>1) {
            System.out.println("Count of ₹1 :"+(int)(cur/1));
            cur = cur%1;
        }
    }  
}  
