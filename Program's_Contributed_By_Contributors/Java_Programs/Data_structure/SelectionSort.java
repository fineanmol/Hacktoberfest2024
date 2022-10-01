class SelectionSort{

    // Selection sort algorithm
    public static void sort(int[] arr){
        
        // Iterate through the array from index 0 to length of array
        for (int i = 0; i < arr.length; i++) {
            
            // Store current index as min Index
            int minIndex = i;
            
            // Store current value of array as minimum
            int min = arr[i];
            
            // Iterate through another loop from index i+1 to length of array
            for (int j = i+1; j < arr.length; j++) {
                
                // Check if current jth element is less than minimum value
                if(arr[j] < min){
                    
                    // Update minimum index
                    minIndex = j;

                    // Update minimum value
                    min = arr[j];
                }
            }
            
            // Swap the current value of array with minimum value index found
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    // Function to print array
    public static void PrintArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    // Main method
    public static void main(String[] args) {
        int[] arr = {3,1,6,2,8,4};
        sort(arr);
        PrintArray(arr);
    }
}