import java.util.*;
class InsertionSort
{
    public static void main(String args[])
    {
        Scanner d=new Scanner(System.in);
        int i,j,t,k,min,p;
        int a[]=new int[n];
        for(i=0;i<n;i++)
            a[i]=d.nextInt();
            
        for(i=1;i<n;i++)//1 ->n
        {
            t=a[i];
            j=i-1;
            while(j>=0 && t<a[j])
            {
                a[j+1]=a[j];
                j--;
            }
            a[j+1]=t;
        }
        for(i=0;i<n;i++)
            System.out.print(a[i]+" ");
    }
}
