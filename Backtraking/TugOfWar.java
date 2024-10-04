import java.util.*; 

class TugOfWar 
{ 
    public int min_diff; 
    
    void TOWUtil(int arr[], int n, boolean curr_elements[], 
            int no_of_selected_elements, boolean soln[], 
            int sum, int curr_sum, int curr_position) 
    { 
        if (curr_position == n) 
            return; 

        if ((n / 2 - no_of_selected_elements) > 
                (n - curr_position)) 
            return; 

        TOWUtil(arr, n, curr_elements, 
            no_of_selected_elements, soln, sum, 
            curr_sum, curr_position+1); 

        no_of_selected_elements++; 
        curr_sum = curr_sum + arr[curr_position]; 
        curr_elements[curr_position] = true; 

        if (no_of_selected_elements == n / 2) 
        { 
            if (Math.abs(sum / 2 - curr_sum) < 
                                min_diff) 
            { 
                min_diff = Math.abs(sum / 2 - 
                                curr_sum); 
                for (int i = 0; i < n; i++) 
                    soln[i] = curr_elements[i]; 
            } 
        } 
        else
        { 
            TOWUtil(arr, n, curr_elements, 
                    no_of_selected_elements, 
                    soln, sum, curr_sum, 
                    curr_position + 1); 
        } 

        curr_elements[curr_position] = false; 
    } 

    void tugOfWar(int arr[]) 
    { 
        int n = arr.length; 
        boolean[] curr_elements = new boolean[n]; 
        boolean[] soln = new boolean[n]; 

        min_diff = Integer.MAX_VALUE; 

        int sum = 0; 
        for (int i = 0; i < n; i++) 
        { 
            sum += arr[i]; 
            curr_elements[i] = soln[i] = false; 
        } 

        TOWUtil(arr, n, curr_elements, 0, 
                soln, sum, 0, 0); 

        System.out.print("The first subset is: "); 
        for (int i = 0; i < n; i++) 
        { 
            if (soln[i] == true) 
                System.out.print(arr[i] + " "); 
        } 
        System.out.print("\nThe second subset is: "); 
        for (int i = 0; i < n; i++) 
        { 
            if (soln[i] == false) 
                System.out.print(arr[i] + " "); 
        } 
    } 
    
    public static void main (String[] args) 
    { 
        Scanner sc = new Scanner(System.in); 
        System.out.print("Enter the number of elements in the array: "); 
        int n = sc.nextInt(); 
        int[] arr = new int[n]; 
        
        System.out.println("Enter the elements of the array: "); 
        for (int i = 0; i < n; i++) { 
            arr[i] = sc.nextInt(); 
        } 
        
        TugOfWar a = new TugOfWar(); 
        a.tugOfWar(arr); 
    } 
} 
