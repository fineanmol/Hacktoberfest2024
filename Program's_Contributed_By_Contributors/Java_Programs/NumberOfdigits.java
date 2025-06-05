public class NumberOfdigits {
    public static void main(String[] args) {
        int n = 35567;
        int b = 10;
        int ans = (int)(Math.log(n)/Math.log(b)) + 1;
        System.out.println(ans);
    }
}
