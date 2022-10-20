import java.util.*;
public class KMP_algorithm{
    public static int[] Array(String str){
        int index=0;
        int[]arr=new int[str.length()];
        for(int i=1;i<=str.length()-1;i++){
            if(str.charAt(i)==str.charAt(index)){
                arr[i]=index+1;
                index++;
            }
            else{
                if(index!=0){
                    index=arr[index-1];
                    arr[i]=index+1;
                }
                else{
                    arr[i]=0;
                }
            }
        }
        return arr;
    }
public static boolean KMP(String str,String str1){
    int lps[]=Array(str1);
    int i=0;
    int j=0;
    while(i<str.length()&&j<str1.length()){
        if(str.charAt(i)==str.charAt(j)){
            i++;
            j++;
        }
        else{
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    if(j==str1.length()){
        return true;
    }
    return false;
}
    public static void main(String[]args){
        Scanner input=new Scanner(System.in);
        String str=input.next();
        String str1=input.next();
        System.out.println(KMP(str,str1));
        input.close();
    }
    
}
