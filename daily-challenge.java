package co.dailychallenge;


class Solution {
	public static void main(String[] args) {
		int [] arr ={1,0,2};
		int res= candy(arr);
		System.out.println();
		System.out.println(res);
	}
    public static int candy(int[] ratings) {
        int []L=new int [ratings.length];
        int []R=new int [ratings.length];
        int max=0;
        for (int x: L){
            x=1;
            
        }
       
        for (int x: R){
            x=1;
            
        }
        
        for (int i=1;i<L.length;i++){
            if (L[i]>L[i-1]){
                int temp= Math.max(L[i],L[i-1]);
                L[i]=temp+1;
                System.out.print(temp+" ");
                 
               
            }
           
            
        }
         System.out.println();
        
        for (int i=R.length-2;i>=0;i--){
             if (R[i]>R[i+1]){
                int temp= Math.max(R[i],R[i+1]);
                R[i]=temp+1;
                
            }
             System.out.print(R[i]+" ");
            
        }
        
        for (int i=0;i<ratings.length;i++){
            max=max+Math.max(L[i],R[i]);
        }
        
        
        return max;
        
    }
}
