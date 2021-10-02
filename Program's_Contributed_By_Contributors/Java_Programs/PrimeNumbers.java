import java.util.*;
import java.lang.*;
import java.io.*;

// Using the sieve of Eratosthenes
public class PrimeNumbers {
    public static List<Integer> calcPrimeNumbers(int n) {
        boolean[] isPrimeNumber = new boolean[n + 1]; // boolean defaults to
        // false
        List<Integer> primes = new ArrayList<Integer>();
        for (int i = 2; i < n; i++) {
            isPrimeNumber[i] = true;
        }
        for (int i = 2; i < n; i++) {
            if (isPrimeNumber[i]) {
                primes.add(i);
                // now mark the multiple of i as non-prime number
                for (int j = i; j * i <= n; j++) {
                    isPrimeNumber[i * j] = false;
                }
            }

        }

        return primes;
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the value of n");
        int n=sc.nextInt();
        List<Integer> calcPrimeNumbers = calcPrimeNumbers(n);
        for (Integer integer : calcPrimeNumbers) {
            System.out.println(integer);
        }
    }
}
