import java.util.Scanner;
public class HRhombusstar
{
    
    public static void main(String[] args)
    {
             
	Scanner sc=new Scanner(System.in);
	System.out.println("Enter N : ");
	int n=sc.nextInt();
	 
              System.out.print("Enter Symbol : ");
	
              char c = sc.next().charAt(0);

	for(int i=1;i<=n;i++)
               {

                        for(int j=1;j<=n-i;j++)
                
                        {
                               System.out.print(" ");
                        }
	     if(i==1 || i==n)
                       for(int j=1;j<=n;j++)
                
                        {
                               System.out.print(c);
                        }
                   else
	    {
                	       for(int j=1;j<=n;j++)
                
                	       {  
                            		if(j==1 || j==n)
                               	System.out.print(c);
                              	else
                             
                            	               System.out.print(" ");
                                   }
                     }
                            System.out.println();
                       
               }             

 
                
    }
}
