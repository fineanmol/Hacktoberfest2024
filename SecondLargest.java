import java.util.*;
import java.lang.*;
import java.io.*;

public class SecondLargest{
	public static void main (String[] args){
		Scanner sc = new Scanner(System.in);
    int [] marks = new int[5];
    int temp;
    for(int i=0;i<5;i++){
       marks[i]=sc.nextInt();
    }
     
    for(int i=0;i<5;i++){
         for(int j=i+1;j<5;j++){
           if(marks[i]>marks[j]){
            temp=marks[i];
            marks[i]=marks[j];
            marks[j]=temp;
           }
          }
    }
    System.out.println(marks[5-2]);
	}
}
