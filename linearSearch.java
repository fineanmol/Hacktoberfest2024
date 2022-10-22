import java.util.Scanner;
 class linearSearch {

    public static void main(String[] args) {
      int[] a  ={12,24,36,48,50,60,1,8,9}  ;
     System.out.println("Enter the number to get searched ");
     Scanner in = new Scanner(System.in);
     int target = in.nextInt();
      int answer = search(a, target);
      System.out.println(answer);
      in.close();
    }
    

    static int search(int[] arr , int target){
        if (arr.length==0){
            return Integer.MAX_VALUE;
        }
       
       for(int i=0;i<arr.length ; i++){
         
        if(arr[i]== target )
            {
                return i;
            }
           

        }
        
        return Integer.MAX_VALUE;
    
   

    }
}
