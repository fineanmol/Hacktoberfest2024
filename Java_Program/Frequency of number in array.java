public class Frequency {  
    public static void main(String[] args) {  
        int [] arr = new int [] {9, 2, 5, 3, 5, 2, 9, 5, 0};  
        
        int [] f = new int [arr.length];  
        int m = -1;  
        for(int i = 0; i < arr.length; i++){  
            int count = 1;  
            for(int j = i+1; j < arr.length; j++){  
                if(arr[i] == arr[j]){  
                    count++;  
                    
                    fr[j] = m;  
                }  
            }  
            if(f[i] != m)  
                f[i] = count;  
        }  
       System.out.println(" Element | Frequency");  
        
        for(int i = 0; i < f.length; i++){  
            if(f[i] != m)  
                System.out.println("    " + arr[i] + "    |    " + fr[i]);  
        }  
       
    }}  
