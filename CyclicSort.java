import java.util.* ; 
class CyclicSort{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in); 
        System.out.println("Note : Number should in the range of (1 to n) "); 
        System.out.println("Enter the number of element"); 
        int n = scan.nextInt(); 
        int[] arr = new int[n] ; 
        for(int i = 0 ; i<n; i++) arr[i] = scan.nextInt(); 
        System.out.println("Before Sorting ");
        for(int num : arr) System.out.print(num + " ") ;  
       
        int idx = 0 ; 
        while(idx<n){
            if(arr[idx]>0 && arr[idx]<=n && arr[idx]!=arr[arr[idx] -1 ]){
                int j = arr[idx] -1 ; 
                int temp = arr[idx] ; 
                arr[idx]  = arr[j] ; 
                arr[j]  = temp ; 
            }else {
                idx++; 
            }
        }
        System.out.println() ; 
        System.out.println("After Sorting "); 
        for(int num  : arr) System.out.print(num + " "); 
    }
}