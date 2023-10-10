//Tower of Hanoi puzzle solved in Java 
class recursive {
  
    public static void towerofhnoi(int n, String src, String Helper, String dest) {
        // Base case: If there's only one disk to move, print the move and return
        if (n == 1) {
            System.out.println("Transfer disk " + n + " from " + src + " to " + dest);
            return;
        }
        
        // Move (n-1) disks from source to helper using destination as the auxiliary peg
        towerofhnoi(n - 1, src, dest, Helper);
        
        // Move the largest disk from source to destination
        System.out.println("Transfer disk " + n + " from " + src + " to " + dest);
        
        // Move (n-1) disks from helper to destination using source as the auxiliary peg
        towerofhnoi(n - 1, Helper, src, dest);
    }
    
    // Method to calculate the factorial of a number
    public static int factorial(int n) {
        if (n <= 0) {
            return 1;
        } else {
            // Calculate the factorial using recursion
            return n * factorial(n - 1);
        }
    }
    
    // Variables for Fibonacci series
    static int first = 0, second = 1, next = 0;
    
    // Method to print the Fibonacci series
    public static void fabonacci(int count) {
        // Base case: If count is greater than 0, continue printing Fibonacci series
        if (count > 0) {
            next = first + second;
            first = second;
            second = next;
            System.out.print(" " + next);
            fabonacci(count - 1); // Recursive call to print the next term
        }
    }
    
    public static void main(String[] args) {
        int n = 2;
        long t1 = System.nanoTime();
        
        // Solve the Tower of Hanoi problem for 'n' disks
        towerofhnoi(n, "S", "H", "D");
        
        long t2 = System.nanoTime();
        long time = t2 - t1; // Measure the time taken to solve the Tower of Hanoi
        
        int num = 22; // Calculate the factorial of 22
        System.out.println(factorial(num));
        
        System.out.print(first + " " + second + " ");
        
        int m = 8;
        fabonacci(m - 2); // Print the first 8 terms of the Fibonacci series
    }
}
