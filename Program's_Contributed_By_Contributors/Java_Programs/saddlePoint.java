import java.util.*;
public class pro2_saddlePoint6
{
    static void main()
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("enter no. of rows of square matrix");
        int n=sc.nextInt();
        int a[][]=new int[n][n];
        System.out.println("enter elements");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                a[i][j]=sc.nextInt();
            }
        }
        System.out.println("original array");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                System.out.print(a[i][j]+"\t");
            }
            System.out.println();
        }
        
        int min=0,max=0,f=0,x=0;
        
        for(int i=0;i<n;i++)
        {
            min=a[i][0];
            x=0;
            for(int j=0;j<n;j++)
            {
                if(a[i][j]<min)
                {
                    min=a[i][j];
                    x=j;
                }
            }
        
        
           max=a[0][x];
           for(int k=0;k<n;k++)
           {
            if(a[k][x]>max)
            {
                max=a[k][x];
            }
           }
           if(max==min)
           {
            System.out.println("saddle point= "+max); 
            f=1;
           }
       }
       if(f==0)
       {
           System.out.println("saddle point does not exist");
       }
    }
}
/*SAMPLE OUTPUT
 * enter no. of rows of square matrix
3
enter elements
4
5
6
7
8
9
5
1
3
original array
4    5    6    
7    8    9    
5    1    3    
saddle point= 7
 */
