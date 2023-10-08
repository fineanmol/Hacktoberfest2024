class sorting {
    
    public static void bubbleSort(int [] sort_arr, int len){
        
        for (int i=0;i<len-1;++i){

            for(int j=0;j<len-i-1; ++j){

                if(sort_arr[j+1]<sort_arr[j]){

                    int swap = sort_arr[j];
                    sort_arr[j] = sort_arr[j+1];
                    sort_arr[j+1] = swap;

                }
            }
        }
    }
    
    public static void main( String args[] ) {
        int [] array = {10,5,3,1,24,12};
        int len = array.length;
        bubbleSort(array,len);

        for(int i = 0; i<len; ++i){
            System.out.print(array[i] + " ");
        }
    }
}
