import java.util.Scanner;
public class sortingalgorithms{


static void printarray(int [] array){
    for(int i = 0;i<array.length;i++){
        System.out.print(array[i]+"\t");
    }
}

static void inputarray(int [] array){
    Scanner sc = new Scanner(System.in);
    for(int i=0; i<array.length; i++){  
    array[i] = sc.nextInt();
}
}

static void bubblesort(int [] array){
    for(int i=0;i<array.length-1;i++){
        for(int j=0;j<array.length-i-1;j++){
            if(array[j]>array[j+1]){
                int temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }
    printarray(array);
}

static void selectionsort(int [] array){
    for(int i=0;i<array.length-1;i++){
        int smallest = i;
        for(int j=i+1;j<array.length;j++){
            if(array[smallest]>array[j]){
                smallest = j;
            }
        }
        int temp = array[smallest];
        array[smallest]= array[i];
        array[i] = temp;

    }
    printarray(array);
}

static void insertionsort(int [] array){
    for (int i = 1; i < array.length; i++) {
        int current  = array[i];
        int j = i-1;
        while(j>=0 && current<array[j]){
            array[j] = array[j+1];
            j--;
        }
        array[j+1] = current;
    }
    printarray(array);
}

public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the size of array --->");
    int n = sc.nextInt();
    int  array [] = new int[n];
    System.out.println("Enter the array --->");
    inputarray(array);
    // bubblesort(array);
    // selectionsort(array); 
    insertionsort(array);
    sc.close();
}
}
