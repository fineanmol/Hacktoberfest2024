public class ValidPerfectSquare {
    
    public static void main(String[] args) {
        System.out.println(isPerfectSquare(25));
        System.out.println(isPerfectSquare(22));
    }

    static boolean isPerfectSquare(int num) {
        int start = 1;
        int end = num;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int div = num/mid, remainder = num % mid;
            if (div == mid && remainder == 0) {
                return true;
            }
            if (div > mid) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return false;
    }
}