public class printPairs {
    public static void pairs(int numbers[]){
        int tp=0;
        for(int i=0;i<numbers.length;i++){
            int curr = numbers[i];
            for(int j = i+1; j<numbers.length; j++){
                System.out.print("("+ curr + "," + numbers[j] + ")");
                tp++;
            }
            System.out.println();
        }
        System.out.println("Total Pairs: "+tp);

    }
    public static void main(String args[]){
        int numbers[] = {1,2,3,4,5,6,7,8,9};
        pairs(numbers);
    }
    
}
