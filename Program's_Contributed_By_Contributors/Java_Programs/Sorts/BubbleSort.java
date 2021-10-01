import java.util.*;
class BubbleSort
//select a cell and compare it with next cell
{
    public static void main(String args[])
    {
        Scanner d=new Scanner(System.in);
        int i,j,t,k,min,p,n;
        n=d.nextInt();
        int a[]=new int[n];
        for(i=0;i<n;i++)
            a[i]=d.nextInt();
        for(i=0;i<n;i++)//0 ->n
        {
            for(j=0;j<n-1-i;j++)//0 ->n-1-i
            {
                if(a[j]>a[j+1])//next element
                {
                    t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;
                }
            }
        }
        for(i=0;i<n;i++)
            System.out.print(a[i]+" ");
    }
}
