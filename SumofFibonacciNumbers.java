public class FibonacciSum {
    public static void main(String[] args) {
        int limit = 100; // Define the limit for the Fibonacci numbers
        long fibonacciSum = calculateFibonacciSum(limit);

        System.out.println("The sum of Fibonacci numbers up to " + limit + " is: " + fibonacciSum);
    }

    public static long calculateFibonacciSum(int limit) {
        long fibonacciSum = 0;
        long prev = 0;
        long current = 1;

        while (current <= limit) {
            if (current % 2 == 0) { // Check if the current Fibonacci number is even
                fibonacciSum += current;
            }

            // Calculate the next Fibonacci number
            long next = prev + current;
            prev = current;
            current = next;
        }

        return fibonacciSum;
    }
}
