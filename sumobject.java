import java.util.*;
class summation
{
    int sum;
    int a ,b;
    summation()
    {
        sum = 0;
        a = 0 ;
        b = 0;
    }
    public void addition()
    {
        this.sum = this.b;
        for (int i = 1; i <= this.a; i++) 
        {
            this.sum++;
        }
    }
    public void input()
    {
        Scanner sc = new Scanner (System.in);
        System.out.println("Enter the two numbers\n");
        a = sc.nextInt();
        b = sc.nextInt();
        sc.close();
    }
    public void display()
    {
        System.out.println("The sum of two elements are "+sum);
    }
}
public class add
{
    public static void main(String[] args)
    {
        summation ob = new summation();
        ob.input();
        ob.addition();
        ob.display();
    }
    
}
