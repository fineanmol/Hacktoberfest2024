public class MinElms {
    public static void main(String[] args) {
        int[] arr = { 20, 36, 8, 10, 12 };
        int min = arr[0];
        for (int i = 0; i < arr.length; i++) {

            if (arr[i] < min) {
                min = arr[i];
            }
        }
        System.out.println(min);
    }
}
