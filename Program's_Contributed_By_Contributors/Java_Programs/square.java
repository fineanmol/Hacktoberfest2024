import java.util.Scanner;
class sq{
public static void main(String args[]){
    Scanner in=new Scanner(System.in);
    int i,n;
    System.out.println("enter no of terms");
    n=in.nextInt();
    for(i=1;i<=10;i++){
        if(i%2==0)
        System.out.println(Math.pow(i,2)+i);
        else
        System.out.println(Math.pow(i,3)+1);
    }
}
}
