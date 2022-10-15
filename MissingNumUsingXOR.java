class MissingNumXOR{
    public static int Num(int[] arr){
        int xor = 0;
        for(int i = 0 ; i<= (arr.length)+1 ; i++){
            xor ^= i;
        } 
        for(int j : arr){
            xor ^= j;
        }
        return xor;
    }
    public static void main(String args[]){
        int[] arr = { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 9 ,10};
        System.out.print("Missing number: "+Num(arr));
    }
}
