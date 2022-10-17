import java.util.Arrays;
import java.util.Scanner;

class functions{
    int total_len;
    int n;
    int[][] main_arrr;
    int[][] partision(int[] arr_1 , int n ){
        total_len = arr_1.length;
        this.n = n;
        int val_2 = arr_1.length/n;
        int[][] main_arr = new int[n][val_2];
        int temp_1 = 0;
        int temp_2 = 0;
        for (int x:arr_1){
            if (temp_1<=n-1){
                if (temp_2<=(val_2-1)){
                    main_arr[temp_1][temp_2] = x;
                    temp_2+=1;
                }
                else{
                    temp_1 +=1;
                    main_arr[temp_1][0] = x;
                    temp_2=1;
                }
            }
        }
        this.main_arrr = main_arr;
        return main_arr;
    }
    void show_partition(int[][] main_arr){
        for (int x=0;x<n;x++){
            System.out.println(Arrays.toString(main_arr[x]));
        }
    }
    void give_to_sort(int[][] main2_arrr){
        for (int x=0;x<n;x++){
            sort(main2_arrr[x]);
            System.out.println(Arrays.toString(main_arrr[x]));
        }
    }

    void sort(int[] arr){
        int n = arr.length;  
        int temp = 0;  
        for(int i=0; i < n; i++){  
            for(int j=1; j < (n-i); j++){  
                if(arr[j-1] > arr[j]){  
                    //swap elements  
                    temp = arr[j-1];  
                    arr[j-1] = arr[j];  
                    arr[j] = temp;  
                    }  
                          
                }  
        }

    }
    int[] make_simple(int[][] a,int total){
        int i=0;
        int j=0;
        int[] return_arr = new int[total];
        for(int x=0 ; x<total; x++){
            if(i<a[j].length){
                return_arr[x] = a[j][i];
                i+=1;
            }
            else{
                j+=1;
                return_arr[x] = a[j][0];
                i=1;
            }
        }
        return return_arr;
    }
    void merge_n_arrays(int[][] a,int b){
        int[] output = make_simple(a,b);
        sort(output);
        System.out.println(Arrays.toString(output));
    }

}
class merge_threds extends Thread{
    int[][] main_arr;
    int b;
    public void run(){
        functions f1 = new functions();
        f1.merge_n_arrays(main_arr,b);
        System.out.println("this ran");
    }
    void push_values(int[][] main_arr, int b){
        this.main_arr = main_arr;
        this.b = b;
    }
}
class sort_thread extends Thread{
    int[] a;
    public void predata(int[] a) {
        functions f2 = new functions();
        f2.sort(a);
    }
}
class sample_2{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("What do u want to give the length of the array: ");
        int zuba = sc.nextInt();
        int[] arr_1 = new int[zuba]; // {2,1,6,5,4,3,9,5,7};
        System.out.println("Enter values");
        for(int x=0;x<zuba;x++){
            int jugo = sc.nextInt();
            arr_1[x] = jugo; 
        }
        functions f1 = new functions();
        System.out.println("IN how many parts do u want to divide it: ");
        int n = sc.nextInt();
        System.out.println("DIVIDED TO N ARRAYS");
        int[][] main_arr = f1.partision(arr_1,n);
        f1.show_partition(main_arr);
        System.out.println("N SORTED ARRAYS");
        for (int x=0;x<n;x++){
            sort_thread t1 = new sort_thread();
            t1.predata(main_arr[x]);
        }
        f1.show_partition(main_arr);
        System.out.println("FINAL ARRAY");
        merge_threds t2 = new merge_threds();
        t2.push_values(main_arr,arr_1.length);
        t2.start();
        sc.close();
    }
}
