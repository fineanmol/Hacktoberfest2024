import java.util.Scanner;

public class selection_sort {




    public static void printArray(int arr[]) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        //  System.out.println();
    }

    public static void main(String args[]) {
        Scanner sc=new Scanner(System.in);
        int size= sc.nextInt();
        // int arre[] = {7, 8, 1, 3, 2};
        int arres[]=new int[size];
        System.out.println("Enter the number");
        for(int i=0;i<size;i++)
        {

            // int a= sc.nextInt();`
            arres[i]= sc.nextInt();
        }


        //selection sort
        for(int i=0;i<arres.length-1;i++){
            int smallest=i;
            for(int j=i+1;j<arres.length;j++){
                if(arres[smallest]>arres[j]){
                    smallest=j;
                }
            }
            int temp=arres[smallest];
            arres[smallest]=arres[i];
            arres[i]=temp;

        }

        printArray(arres);
    }
}
