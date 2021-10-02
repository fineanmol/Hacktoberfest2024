import java.util.*;
class QuickSort 
{
    static int count = 0;
    static void sort(int a[],int l,int h)
    {
        count++;
        if(l<h)
        {
            int pivot = partition(a,l,h);
            sort(a,l,pivot-1);
            sort(a,pivot+1,h);
        }
    }

    //best case        
    static int partition(int a[],int l, int h)    
    {
        Scanner sc=new Scanner(System.in);

        int pivot=a[(l+h)/2];
        int i=l;
        int j=h;

        while(i<=j)
        {
            while(i<=j && a[j]>pivot)
            {
                j=j-1;count++;
            }
            while(i<=j && a[i]<pivot)
            {
                i+=1;count++;
            }
            if(i<=j)
            {
                int temp=a[j];
                a[j]=a[i];
                a[i]=temp;count++;
            }
            
            if(i==j)
                break;
        }
        count++;

        return i;
    }

    //worst case
    /*static int partition(int a[],int l,int h)
    {
    int i = l - 1;int t;
    int pivot = a[h];
    for(int j = l;j<h;j++)
    {
    if(a[j] < pivot)
    {
    i++;
    t = a[i];
    a[i] = a[j];
    a[j] = t;
    }
    count+=2;
    }
    count++;
    i++;
    t = a[i];
    a[i] = a[h];
    a[h] = t;
    return i;
    }*/

    public static void main(String args[])
    {
        int size = 10;
        int a[] = new int[size];
        
        Random r=new Random();
        for(int i = 0;i<size;i++)
        {
            a[i] = r.nextInt(50);
        }
        //int a[]={1,2,8,3,4,9,7,5,10,6};
        System.out.print("\nBefore Sorting: ");
        for(int i = 0;i<size;i++)
            System.out.print(a[i]+" ");
        sort(a,0,size-1);
        System.out.print("\nSorted array is: ");
        for(int i = 0;i<size;i++)
            System.out.print(a[i]+" ");

        System.out.println("\nCount:"+count);

    }
}
