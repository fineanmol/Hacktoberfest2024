public class PrimeNumberSum {
    public static void main(String[] args) {
        int lowerBound = 2; // Define the lower bound of the range
        int upperBound = 100; // Define the upper bound of the range

        long primeSum = calculatePrimeSum(lowerBound, upperBound);

        System.out.println("The sum of prime numbers between " + lowerBound + " and " + upperBound + " is: " + primeSum);
    }

    public static boolean isPrime(int num) {
        if (num <= 1) {
            return false;
        }
        if (num <= 3) {
            return true;
        }
        if (num % 2 == 0 || num % 3 == 0) {
            return false;
        }

        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) {
                return false;
            }
        }

        return true;
    }

    public static long calculatePrimeSum(int lowerBound, int upperBound) {
        long primeSum = 0;

        for (int i = lowerBound; i <= upperBound; i++) {
            if (isPrime(i)) {
                primeSum += i;
            }
        }

        return primeSum;
    }
}
